/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_draw_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:36 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/29 19:39:58 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int			ray_is_in_the_map(int x, int y, t_env *e)
{
	if (x < 0 || x >= e->data.max_x || y < 0 || y >= e->data.max_y)
		return (0);
	return (1);
}

void		get_wall_height(t_env *e, int column, int tid)
{
	e->wall[tid].tex = (e->ray[tid].hor.dist <= e->ray[tid].vert.dist) ? 0 : 1;
	e->wall[tid].dist = (e->ray[tid].hor.dist <= e->ray[tid].vert.dist) ? \
		e->ray[tid].hor.dist : e->ray[tid].vert.dist;
	e->wall[tid].texture_x = (e->ray[tid].hor.dist <= e->ray[tid].vert.dist) \
	? (Uint32)(e->ray[tid].hor.x) % TILE_SIZE : (Uint32)(e->ray[tid].vert.y) \
	% TILE_SIZE;
	if (!e->wall[tid].tex && (e->ray[tid].angle > 0 \
	&& e->ray[tid].angle < e->angle.a_180))
		e->wall[tid].tex = 2;
	else if (e->wall[tid].tex && (e->ray[tid].angle > e->angle.a_90 \
	&& e->ray[tid].angle < e->angle.a_270))
		e->wall[tid].tex = 3;
	e->wall[tid].dist *= e->fisheye_table[column];
	e->wall[tid].dist < 0.1 ? e->wall[tid].dist = 0.1 : 0;
	if (e->wall[tid].dist <= 0)
		e->wall[tid].bottom = 0;
	else
	{
		e->wall[tid].height = WALL_HEIGHT * e->player.plane_dist \
		/ e->wall[tid].dist;
		e->wall[tid].bottom = (ceil((e->player.plane_dist / e->wall[tid].dist) \
		* e->player.height + e->horizon)) - e->wall[tid].height * e->ray[tid].layer;
		e->wall_heights[column] = e->wall[tid].height;
		e->wall[tid].top = e->wall[tid].bottom - (int)e->wall[tid].height;
	}
}

static void	crop_wall(t_env *e, float *offset, double ratio, int tid)
{
	if (e->wall[tid].top < 0)
	{
		*offset = -(e->wall[tid].top * ratio);
		e->wall[tid].top = 0;
	}
	else
		*offset = 0;
	if (e->wall[tid].bottom >= e->render_limit)
		e->wall[tid].bottom = e->render_limit;
}

void		draw_wall(t_env *e, int column, int tid)
{
	int			y;
	double		ratio;
	float		texture_y;

	ratio = TILE_SIZE / e->wall[tid].height;
	crop_wall(e, &texture_y, ratio, tid);
	y = e->wall[tid].top - 1;
	while (++y < e->wall[tid].bottom + 1)
	{
		e->buff[y * WIN_W + column] = \
	e->files.wall[e->wall[tid].tex][((int)texture_y << e->tile_shift) \
	+ e->wall[tid].texture_x];
		texture_y += ratio;
		if (texture_y >= TILE_SIZE)
			break ;
	}
}
