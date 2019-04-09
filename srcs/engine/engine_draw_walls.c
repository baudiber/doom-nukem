/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_draw_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:36 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/09 20:12:26 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int			ray_is_in_the_map(t_point_int pt, t_env *e)
{
	//pourquoi pas BOOl ?
	if (pt.x < 0 || pt.x >= e->data.max_x || pt.y < 0 || pt.y >= e->data.max_y)
		return (0);
	return (1);
}


static void	crop_next_wall(t_env *e, int tid)
{
	e->tmp[tid] = e->wall[tid];
	if (e->wall[tid].top >= e->prev_wall[tid].top && e->wall[tid].bottom <= e->prev_wall[tid].bottom)
	{
		//printf("case 1: inside of prev\n");
		e->wall[tid].bottom = 0;
		return ;
	}
	/*if (e->wall[tid].top <= e->prev_wall[tid].top && e->wall[tid].bottom >= e->prev_wall[tid].bottom)
	{
		printf("case 0: bigger than prev\n");
		e->wall[tid].bottom = 0;
		return ;
	}
	*/
	if (e->wall[tid].bottom < e->prev_wall[tid].top && e->wall[tid].bottom < e->prev_wall[tid].bottom)
	{
		//printf("case 2: fully above prev\n");
		return ;
	}
	if (e->wall[tid].top > e->prev_wall[tid].bottom && e->wall[tid].bottom > e->prev_wall[tid].bottom)
	{
		//printf("case 3: fully below prev\n");
		return ;
	}
	if (e->wall[tid].bottom >= e->prev_wall[tid].top && e->wall[tid].top < e->prev_wall[tid].top)
	{
		//printf("case 4: we can see the top part\n");
		//printf("top %d ptop %d bottom %d pbottom %d\n", e->wall[tid].top, e->prev_wall[tid].top, e->wall[tid].bottom, e->prev_wall[tid].bottom);
		e->wall[tid].bottom = e->prev_wall[tid].top;
		return ;
	}
	else if (e->wall[tid].top <= e->prev_wall[tid].bottom)
	{
		//printf("case 5: we can see the bottom part\n");
		//printf("top %d ptop %d bottom %d pbottom %d\n", e->wall[tid].top, e->prev_wall[tid].top, e->wall[tid].bottom, e->prev_wall[tid].bottom);
		e->wall[tid].top = e->prev_wall[tid].bottom;
		//offset pb here // maybe save the diff or do that somewhere else
		return ;
	}
	printf("case unknown, top %d ptop %d bottom %d pbottom %d\n", e->wall[tid].top, e->prev_wall[tid].top, e->wall[tid].bottom, e->prev_wall[tid].bottom);
}

void		get_wall_height(t_env *e, int column, int tid)
{
	e->wall[tid].dist *= e->fisheye_table[column];
	e->wall[tid].dist < 0.1 ? e->wall[tid].dist = 0.1 : 0;
	if (e->wall[tid].dist <= 0 || e->wall[tid].dist == 2147483647)
		e->wall[tid].bottom = 0;
	else
	{
		// (WALL_HEIGHT << e->player.plane_dist) / e->wall[tid].dist ??
		e->wall[tid].height = WALL_HEIGHT * e->player.plane_dist \
		/ e->wall[tid].dist;
		e->wall[tid].bottom = ceil(((e->player.plane_dist / e->wall[tid].dist) \
		* e->player.height + e->horizon) - e->wall[tid].height * e->ray[tid].layer);
		e->wall_dist[e->ray[tid].layer][column] = e->wall[tid].height;
		e->wall[tid].top = e->wall[tid].bottom - (int)e->wall[tid].height;
		if (e->prev_wall[tid].is_prev)
			crop_next_wall(e, tid);
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
	int			color;
	double		ratio;
	float		texture_y;

	ratio = TILE_SIZE / e->wall[tid].height;
	crop_wall(e, &texture_y, ratio, tid);
	y = e->wall[tid].top - 2;
	while (++y < e->wall[tid].bottom + 1)
	{
		color = e->files.wall[e->wall[tid].tex][((int)texture_y << e->tile_shift) + e->wall[tid].texture_x];
		if (e->wall[tid].shadow)
			color = (color >> 1) & 8355711;
		e->buff[y * WIN_W + column] = color;
		texture_y += ratio;
		if (texture_y >= TILE_SIZE)
			break ;
	}
}
