/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_draw_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 01:59:41 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/13 02:00:43 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void	crop_next_wall(t_env *e, int tid)
{
	e->tmp[tid] = e->wall[tid];
	e->wall[tid].botwall = false;
	if (e->wall[tid].top >= e->prev_wall[tid].top && e->wall[tid].bottom \
		<= e->prev_wall[tid].bottom)
	{
		e->wall[tid].bottom = 0;
		return ;
	}
	if (e->wall[tid].bottom <= e->prev_wall[tid].top)
		return ;
	if (e->wall[tid].top >= e->prev_wall[tid].bottom)
		return ;
	if (e->wall[tid].bottom >= e->prev_wall[tid].top && e->wall[tid].top \
		< e->prev_wall[tid].top)
	{
		e->wall[tid].bottom = e->prev_wall[tid].top;
		return ;
	}
	else if (e->wall[tid].top <= e->prev_wall[tid].bottom)
	{
		e->wall[tid].botwall = true;
		e->wall[tid].top = e->prev_wall[tid].bottom;
		return ;
	}
}

void		get_wall_height(t_env *e, int column, int tid)
{
	e->wall[tid].dist *= e->fisheye_table[column];
	e->wall[tid].dist = e->wall[tid].dist < 0.1 ? 0.1 : e->wall[tid].dist;
	if (e->wall[tid].dist <= 0 || e->wall[tid].dist == 2147483647)
		e->wall[tid].bottom = 0;
	else
	{
		e->wall[tid].height = WALL_HEIGHT * e->player.plane_dist \
			/ e->wall[tid].dist;
		e->wall[tid].bottom = round(((e->player.plane_dist / e->wall[tid].dist)\
			* e->player.height + e->horizon) - e->wall[tid].height \
			* e->ray[tid].layer);
		if (!e->prev_wall[tid].is_prev)
			e->wall_dist[e->ray[tid].layer][column] = e->wall[tid].height;
		e->wall[tid].top = e->wall[tid].bottom - (int)e->wall[tid].height;
		if (e->prev_wall[tid].is_prev)
			crop_next_wall(e, tid);
	}
}

void		draw_reversed(t_env *e, int column, int tid)
{
	int			y;
	int			color;
	double		ratio;
	float		texture_y;

	ratio = TILE_SIZE / e->wall[tid].height;
	texture_y = TILE_SIZE;
	crop_wall_rev(e, &texture_y, ratio, tid);
	y = e->wall[tid].bottom + 1;
	while (--y >= e->wall[tid].top)
	{
		color = e->files.wall[e->wall[tid].tex][((int)texture_y \
				<< e->tile_shift) + e->wall[tid].texture_x];
		if (e->wall[tid].shadow)
			color = (color >> 1) & 8355711;
		if (color ^ 0xFF00FFFF)
			e->buff[y * WIN_W + column] = color;
		texture_y -= ratio;
		if (texture_y < 0)
			break ;
	}
}

void		draw_wall(t_env *e, int column, int tid)
{
	int			y;
	int			color;
	double		ratio;
	float		texture_y;

	ratio = TILE_SIZE / e->wall[tid].height;
	crop_wall(e, &texture_y, ratio, tid);
	y = e->wall[tid].top - 1;
	while (++y < e->wall[tid].bottom + 1)
	{
		color = e->files.wall[e->wall[tid].tex][((int)texture_y \
				<< e->tile_shift) + e->wall[tid].texture_x];
		if (e->wall[tid].shadow)
			color = (color >> 1) & 8355711;
		if (color ^ 0xFF00FFFF)
			e->buff[y * WIN_W + column] = color;
		texture_y += ratio;
		if (texture_y >= TILE_SIZE)
			break ;
	}
}
