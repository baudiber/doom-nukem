/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:45:18 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/23 19:14:46 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static bool			count_sprite(t_data *data)
{
	int				y;
	int				x;
	int				ret;

	y = 0;
	ret = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			if (ft_strnchr("abc", data->sprite[y][x]) > 0)
				ret++;
			x++;
		}
		y++;
	}
	return (ret < 100) ? true : false;
}

static void			stock_sprite(int ind, int y, int x, t_env *e)
{
	if (ind > 100)
		return ;
	e->sprites[ind].tex = e->data.sprite[y][x] - 97;
	e->sprites[ind].visible = true;
	e->sprites[ind].y = (y + 0.5) * TILE_SIZE;
	e->sprites[ind].x = (x + 0.5) * TILE_SIZE;
	e->sprite_nb++;
}

static void			scan_sprite(t_env *e, t_data *data)
{
	int				y;
	int				x;
	int				i;

	i = 0;
	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			if (ft_strnchr("abc", data->sprite[y][x]) > 0)
			{
				stock_sprite(i, y, x, e);
				i++;
			}
			x++;
		}
		y++;
	}
}

void				parse_sprite(t_env *e)
{
	if (!count_sprite(&e->data))
		exit_error(10);
	scan_sprite(e, &e->data);
}
