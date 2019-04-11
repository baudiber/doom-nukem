/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:12:35 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/10 23:10:30 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void			parse_init(t_data *data)
{
	data->pos_y = 0;
	data->pos_x = 0;
	data->pos_z = 0;
	data->max_y = 0;
	data->max_x = 0;
	data->tier_ind = 0;
	data->tier_size = 0;
	data->tier = NULL;
	data->stage = NULL;
	data->cell = NULL;
	ft_memset(data->map, 0, sizeof(data->map));
	if (!(data->scan = ft_strnew(0)))
		exit_error(1, ERR_1);
}

void			parse_start(t_data *data, char *map)
{
	parse_init(data);
	parse_scan(data, map);
	parse_tier(data);
	data->max_y = data->tier_size;
	parse_pos(data);
}

void			parse_quit(t_data *data, int type, char *msg)
{
	(data->scan) ? ft_strdel(&data->scan) : 0;
	(data->tier) ? ft_str_tabdel(&data->tier) : 0;
	(data->stage) ? ft_str_tabdel(&data->stage) : 0;
	(data->cell) ? ft_str_tabdel(&data->cell) : 0;
	exit_error(type, msg);
}

void			parse_pos(t_data *data)
{
	int			i;
	int			j;
	int			k;

	k = -1;
	while (++k < data->tier_ind)
	{
		i = -1;
		while (++i < data->max_y)
		{
			j = -1;
			while (++j < data->max_x)
			{
				if (data->map[DSPRITE][k][i][j] == 'z')
				{
					data->pos_y = i;
					data->pos_x = j;
					data->pos_z = k;
				}
			}
		}
	}
}
