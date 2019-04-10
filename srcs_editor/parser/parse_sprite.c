/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:45:18 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/09 23:36:45 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static bool			count_sprite(t_data *data)
{
	int				z;
	int				y;
	int				x;
	int				ret;

	ret = 0;
	z = -1;
	while (++z < data->tier_ind)
	{
		y = -1;
		while (++y < data->max_y)
		{
			x = -1;
			while (++x < data->max_x)
			{
				if (ft_strnchr("abc", (int)data->map[DSPRITE][z][y][x]) > 0)
					ret++;
			}
		}
	}
	return (ret < 100) ? true : false;
}

static void			stock_sprite(int z, int y, int x, t_env *e)
{
	e->sprites[e->sprite_nb].tex = (int)e->data.map[DSPRITE][z][y][x] - 97;
	e->sprites[e->sprite_nb].y = (y + 0.5) * TILE_SIZE;
	e->sprites[e->sprite_nb].x = (x + 0.5) * TILE_SIZE;
	e->sprites[e->sprite_nb].z = z << e->tile_shift;
	e->sprites[e->sprite_nb].floor = z;
	e->sprites[e->sprite_nb].visible = true;
	e->sprite_nb++;
}

static void			scan_sprite(t_env *e, t_data *data)
{
	int				y;
	int				x;
	int				z;

	z = -1;
	while (++z < data->tier_ind)
	{
		y = -1;
		while (++y < data->max_y)
		{
			x = -1;
			while (++x < data->max_x)
			{
				if (ft_strnchr("abc", (int)data->map[DSPRITE][z][y][x]) > 0)
					(e->sprite_nb < 100) ? stock_sprite(z, y, x, e) : 0;
			}
		}
	}
}

void				parse_sprite(t_env *e)
{
	if (!count_sprite(&e->data))
		exit_error(6, ERR_6);
	scan_sprite(e, &e->data);
}
