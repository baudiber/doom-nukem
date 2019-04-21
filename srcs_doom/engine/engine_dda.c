/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_dda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:35 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/14 00:15:10 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void				get_coord_and_dist(t_env *e, int tid)
{
	e->ray[tid].dda[HOR].map.x = (int)e->ray[tid].dda[HOR].x >> e->tile_shift;
	e->ray[tid].dda[HOR].map.y = (int)e->ray[tid].dda[HOR].y >> e->tile_shift;
	e->ray[tid].dda[VERT].map.x = (int)e->ray[tid].dda[VERT].x >> e->tile_shift;
	e->ray[tid].dda[VERT].map.y = (int)e->ray[tid].dda[VERT].y >> e->tile_shift;
	if (e->ray[tid].dda[HOR].dist != 2147483647)
		e->ray[tid].dda[HOR].dist = (e->ray[tid].dda[HOR].x \
				- e->player.pos.x) * e->i_cos_table[e->ray[tid].angle];
	if (e->ray[tid].dda[VERT].dist != 2147483647)
		e->ray[tid].dda[VERT].dist = (e->ray[tid].dda[VERT].y \
				- e->player.pos.y) * e->i_sin_table[e->ray[tid].angle];
}

static bool				dda(t_env *e, int tid, int column, int i)
{
	if (!ray_is_in_the_map(e->ray[tid].dda[i].map, e))
		return (false);
	if (e->data.map[DWALL][e->ray[tid].layer][e->ray[tid].dda[i].map.y]\
		[e->ray[tid].dda[i].map.x])
	{
		get_wall_type(e, tid, column, i);
		e->ray[tid].dda[i].x += e->ray[tid].dda[i].next_x;
		e->ray[tid].dda[i].y += e->ray[tid].dda[i].next_y;
		e->ray[tid].skip = false;
	}
	else
	{
		e->ray[tid].dda[i].x += e->ray[tid].dda[i].next_x;
		e->ray[tid].dda[i].y += e->ray[tid].dda[i].next_y;
		e->spotvis[e->ray[tid].layer][e->ray[tid].dda[i].map.y]\
		[e->ray[tid].dda[i].map.x] = 1;
		e->ray[tid].skip = true;
	}
	return (true);
}

void					double_dda(t_env *e, int tid, int column)
{
	e->ray[tid].skip = true;
	while (true)
	{
		get_coord_and_dist(e, tid);
		if (e->ray[tid].dda[HOR].dist < e->ray[tid].dda[VERT].dist)
		{
			if (!dda(e, tid, column, HOR))
				return ;
		}
		else
		{
			if (!dda(e, tid, column, VERT))
				return ;
		}
	}
}

void					get_horizontal_hit(t_env *e, int tid)
{
	if (e->ray[tid].angle == 0 || e->ray[tid].angle == e->angle.a_180)
		e->ray[tid].dda[HOR].dist = 2147483647;
	else
	{
		e->ray[tid].dda[HOR].dist = 0.1;
		if (e->ray[tid].angle > 0 && e->ray[tid].angle < e->angle.a_180)
		{
			e->ray[tid].dda[HOR].y = (e->player.map.y << e->tile_shift) \
				+ TILE_SIZE;
			e->ray[tid].dda[HOR].x = e->player.pos.x + e->i_tan_table[e->ray\
				[tid].angle] * (e->ray[tid].dda[HOR].y - e->player.pos.y);
			e->ray[tid].dda[HOR].next_y = TILE_SIZE;
		}
		else
		{
			e->ray[tid].dda[HOR].y = e->player.map.y << e->tile_shift;
			e->ray[tid].dda[HOR].x = e->player.pos.x + e->i_tan_table[e->ray\
				[tid].angle] * (e->ray[tid].dda[HOR].y - e->player.pos.y);
			e->ray[tid].dda[HOR].y--;
			e->ray[tid].dda[HOR].next_y = -TILE_SIZE;
		}
		e->ray[tid].dda[HOR].next_x = e->x_step_table[e->ray[tid].angle];
	}
}

void					get_vertical_hit(t_env *e, int tid)
{
	if (e->ray[tid].angle == e->angle.a_90 || e->ray[tid].angle \
		== e->angle.a_270)
		e->ray[tid].dda[VERT].dist = 2147483647;
	else
	{
		e->ray[tid].dda[VERT].dist = 0.1;
		if (e->ray[tid].angle < e->angle.a_90 || e->ray[tid].angle \
			> e->angle.a_270)
		{
			e->ray[tid].dda[VERT].x = (e->player.map.x << e->tile_shift) \
				+ TILE_SIZE;
			e->ray[tid].dda[VERT].y = e->player.pos.y + e->tan_table[e->ray\
				[tid].angle] * (e->ray[tid].dda[VERT].x - e->player.pos.x);
			e->ray[tid].dda[VERT].next_x = TILE_SIZE;
		}
		else
		{
			e->ray[tid].dda[VERT].x = e->player.map.x << e->tile_shift;
			e->ray[tid].dda[VERT].y = e->player.pos.y + e->tan_table[e->ray\
				[tid].angle] * (e->ray[tid].dda[VERT].x - e->player.pos.x);
			e->ray[tid].dda[VERT].x--;
			e->ray[tid].dda[VERT].next_x = -TILE_SIZE;
		}
		e->ray[tid].dda[VERT].next_y = e->y_step_table[e->ray[tid].angle];
	}
}
