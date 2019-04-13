/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_walls_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 01:59:29 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/13 04:33:37 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		crop_wall(t_env *e, float *texture_y, double ratio, int tid)
{
	if (e->wall[tid].top < 0)
	{
		*texture_y = -(e->wall[tid].top * ratio);
		e->wall[tid].top = 0;
	}
	else
		*texture_y = 0;
	if (e->wall[tid].bottom >= e->render_limit)
		e->wall[tid].bottom = e->render_limit;
}

void		crop_wall_rev(t_env *e, float *texture_y, double ratio, int tid)
{
	if (e->wall[tid].top < 0)
		e->wall[tid].top = 0;
	if (e->wall[tid].bottom >= e->render_limit)
	{
		*texture_y -= (e->wall[tid].bottom - e->render_limit) * ratio;
		e->wall[tid].bottom = e->render_limit;
	}
}

void		get_wall_type(t_env *e, int tid, int column, int i)
{
	if (e->ray[tid].skip)
	{
		e->ray[tid].dda[i].tex = e->data.map[DWALL][e->ray[tid].layer]\
			[e->ray[tid].dda[i].map.y][e->ray[tid].dda[i].map.x];
		e->wall[tid].dist = e->ray[tid].dda[i].dist;
		e->wall[tid].tex = e->data.map[DWALL][e->ray[tid].layer]\
			[e->ray[tid].dda[i].map.y][e->ray[tid].dda[i].map.x];
		e->wall[tid].shadow = e->data.map[DLIGHT][e->ray[tid].layer]\
			[e->ray[tid].dda[i].map.y][e->ray[tid].dda[i].map.x];
		e->wall[tid].texture_x = i ? (Uint32)(e->ray[tid].dda[i].y) \
			% TILE_SIZE : (Uint32)(e->ray[tid].dda[i].x) % TILE_SIZE;
		get_wall_height(e, column, tid);
		if (e->prev_wall[tid].is_prev)
			e->prev_wall[tid] = e->tmp[tid];
		else
			e->prev_wall[tid] = e->wall[tid];
		if (!e->wall[tid].botwall)
			draw_wall(e, column, tid);
		else
			draw_reversed(e, column, tid);
		e->prev_wall[tid].is_prev = true;
	}
}

bool		check_walls(int height, int *offset, int x, int tid)
{
	t_env *e;

	e = call();
	if (e->wall_dist[e->ray[tid].layer][x] > height)
	{
		++*offset;
		return (true);
	}
	return (false);
}
