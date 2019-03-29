/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_drawmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:18:40 by roddavid          #+#    #+#             */
/*   Updated: 2019/03/25 20:55:04 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_map_small(t_env *e)
{
	e->minimap.pady = UI_Y2 / (float)(e->data.max_y);
	e->minimap.padx = UI_Y2 / (float)(e->data.max_x);
	while (++e->minimap.y < e->data.max_y)
	{
		e->minimap.x = -1;
		while (++e->minimap.x < e->data.max_x)
		{
			e->minimap.j = e->minimap.pady * e->minimap.y + 500 - 1;
			e->minimap.j2 = 0;
			while (++e->minimap.j < (e->minimap.pady \
				* (e->minimap.y + 1) + 500) && e->minimap.j < WIN_H)
			{
				e->minimap.i = e->minimap.padx * e->minimap.x + 980 - 1;
				e->minimap.i2 = 0;
				while (++e->minimap.i < (e->minimap.padx \
					* (e->minimap.x + 1) + 980) && e->minimap.i < WIN_W)
				{
					if (e->data.map[e->minimap.y][e->minimap.x] != 0)
					{
						e->buff[WIN_W * e->minimap.j + e->minimap.i] = 0x777777;
						if (e->minimap.j % 2 == 0)
							e->buff[WIN_W * e->minimap.j + e->minimap.i] = 0x444444;
					}
					if (e->data.map[e->minimap.y][e->minimap.x] == 0)
						e->buff[WIN_W * e->minimap.j + e->minimap.i] = 0x1B1B1B;
					e->minimap.i2++;
				}
				e->minimap.j2++;
			}
		}
	}
}

void		draw_map_big(t_env *e)
{
	e->minimap.pady = e->render_limit / (float)(e->data.max_y);
	e->minimap.padx = e->render_limit / (float)(e->data.max_x);
	while (++e->minimap.y < e->data.max_y)
	{
		e->minimap.x = -1;
		while (++e->minimap.x < e->data.max_x)
		{
			e->minimap.j = e->minimap.pady * e->minimap.y - 1;
			e->minimap.j2 = 0;
			while (++e->minimap.j < (e->minimap.pady * (e->minimap.y + 1)) \
			&& e->minimap.j < e->render_limit)
			{
				e->minimap.i2 = 0;
				e->minimap.i = e->minimap.padx * e->minimap.x + 304 - 1;
				while (++e->minimap.i < (e->minimap.padx \
					* (e->minimap.x + 1) + 304) && e->minimap.i < WIN_W)
				{
					if (e->data.map[e->minimap.y][e->minimap.x] != 0)
						e->buff[WIN_W * e->minimap.j + e->minimap.i] = 0x777777;
					e->minimap.i2++;
				}
				e->minimap.j2++;
			}
		}
	}
}
