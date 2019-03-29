/* ************************************************************************** */

/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 12:12:50 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/29 17:45:09 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			parse_init(t_data *data)
{
	data->pos_y = 0;
	data->pos_x = 0;
	data->max_y = 0;
	data->max_x = 0;
	data->process = NULL;
	ft_memset(data->map, 0, sizeof(data->map));
	ft_memset(data->sprite, 0, sizeof(data->sprite));
	if (!(data->scan = ft_strnew(0)))
		exit_error(1);
}

void			parse_quit(t_data *data, int type)
{
	(data->scan) ? ft_strdel(&data->scan) : 0;
	(data->process) ? ft_str_tabdel(&data->process) : 0;
	exit_error(type);
}

void			parse_pos(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while (i < data->max_y)
	{
		j = 0;
		while (j < data->max_x)
		{
			if (data->sprite[i][j] == 'z')
			{
				data->pos_y = i;
				data->pos_x = j;
			}
			j++;
		}
		i++;
	}
}
