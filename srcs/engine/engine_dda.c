/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_dda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:35 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/04 14:44:31 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void					horizontal_dda(t_env *e, int tid)
{
	while (true)
	{
		e->ray[tid].hor.map.x = (int)e->ray[tid].hor.x >> e->tile_shift;
		e->ray[tid].hor.map.y = e->ray[tid].hor.y >> e->tile_shift;
		if (!ray_is_in_the_map(e->ray[tid].hor.map.x, e->ray[tid].hor.map.y, e))
		{
			e->ray[tid].hor.dist = 2147483647;
			e->ray[tid].hor.in_map = false;
			break ;
		}
		else if (e->data.map[DWALL][e->ray[tid].layer][e->ray[tid].hor.map.y][e->ray[tid].hor.map.x])
		{
			e->ray[tid].hor.dist = (e->ray[tid].hor.x - e->player.pos.x) \
				* e->i_cos_table[e->ray[tid].angle];
			e->spotvis[e->ray[tid].layer][e->ray[tid].hor.map.y][e->ray[tid].hor.map.x] = 1;
			e->ray[tid].hor.tex = e->data.map[DWALL][e->ray[tid].layer][e->ray[tid].hor.map.y][e->ray[tid].hor.map.x];
			break ;
		}
		else
		{
			e->ray[tid].hor.x += e->ray[tid].hor.next_x;
			e->ray[tid].hor.y += e->ray[tid].hor.next_y;
			e->spotvis[e->ray[tid].layer][e->ray[tid].hor.map.y][e->ray[tid].hor.map.x] = 1;
		}
	}
}

void					get_horizontal_hit(t_env *e, int tid)
{
	if (e->ray[tid].angle == 0 || e->ray[tid].angle == e->angle.a_180)
	{
		e->ray[tid].hor.dist = 2147483647;
		e->ray[tid].hor.in_map = false;
	}
	else
	{
		if (e->ray[tid].angle > 0 && e->ray[tid].angle < e->angle.a_180)
		{
			e->ray[tid].hor.y = (e->player.map.y << e->tile_shift) + TILE_SIZE;
			e->ray[tid].hor.x = e->player.pos.x \
	+ e->i_tan_table[e->ray[tid].angle] * (e->ray[tid].hor.y - e->player.pos.y);
			e->ray[tid].hor.next_y = TILE_SIZE;
		}
		else
		{
			e->ray[tid].hor.y = e->player.map.y << e->tile_shift;
			e->ray[tid].hor.x = e->player.pos.x \
	+ e->i_tan_table[e->ray[tid].angle] * (e->ray[tid].hor.y - e->player.pos.y);
			e->ray[tid].hor.y--;
			e->ray[tid].hor.next_y = -TILE_SIZE;
		}
		e->ray[tid].hor.next_x = e->x_step_table[e->ray[tid].angle];
	}
}

void					vertical_dda(t_env *e, int tid)
{
	while (true)
	{
		e->ray[tid].vert.map.x = e->ray[tid].vert.x >> e->tile_shift;
		e->ray[tid].vert.map.y = (int)e->ray[tid].vert.y >> e->tile_shift;
		if (!ray_is_in_the_map(e->ray[tid].vert.map.x, \
				e->ray[tid].vert.map.y, e))
		{
			e->ray[tid].vert.dist = 2147483647;
			e->ray[tid].vert.in_map = false;
			break ;
		}
		else if (e->data.map[DWALL][e->ray[tid].layer][e->ray[tid].vert.map.y][e->ray[tid].vert.map.x])
		{
			e->ray[tid].vert.dist = (e->ray[tid].vert.y - e->player.pos.y) \
	* e->i_sin_table[e->ray[tid].angle];
			e->spotvis[e->ray[tid].layer][e->ray[tid].vert.map.y][e->ray[tid].vert.map.x] = 1;
			e->ray[tid].vert.tex = e->data.map[DWALL][e->ray[tid].layer][e->ray[tid].vert.map.y][e->ray[tid].vert.map.x];
			break ;
		}
		else
		{
			e->ray[tid].vert.y += e->ray[tid].vert.next_y;
			e->ray[tid].vert.x += e->ray[tid].vert.next_x;
			e->spotvis[e->ray[tid].layer][e->ray[tid].vert.map.y][e->ray[tid].vert.map.x] = 1;
		}
	}
}

void					get_vertical_hit(t_env *e, int tid)
{
	if (e->ray[tid].angle == e->angle.a_90 || e->ray[tid].angle \
	== e->angle.a_270)
	{
		e->ray[tid].vert.dist = 2147483647;
		e->ray[tid].vert.in_map = false;
	}
	else
	{
		if (e->ray[tid].angle < e->angle.a_90 || e->ray[tid].angle \
			> e->angle.a_270)
		{
			e->ray[tid].vert.x = (e->player.map.x << e->tile_shift) + TILE_SIZE;
			e->ray[tid].vert.y = e->player.pos.y \
	+ e->tan_table[e->ray[tid].angle] * (e->ray[tid].vert.x - e->player.pos.x);
			e->ray[tid].vert.next_x = TILE_SIZE;
		}
		else
		{
			e->ray[tid].vert.x = (e->player.map.x << e->tile_shift);
			e->ray[tid].vert.y = e->player.pos.y \
	+ e->tan_table[e->ray[tid].angle] * (e->ray[tid].vert.x - e->player.pos.x);
			e->ray[tid].vert.x--;
			e->ray[tid].vert.next_x = -TILE_SIZE;
		}
		e->ray[tid].vert.next_y = e->y_step_table[e->ray[tid].angle];
	}
}
