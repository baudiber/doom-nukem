/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_draw_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:36 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/04 19:32:22 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int			ray_is_in_the_map(int x, int y, t_env *e)
{
	if (x < 0 || x >= e->data.max_x || y < 0 || y >= e->data.max_y)
		return (0);
	return (1);
}


static int	crop_next_wall(t_env *e, int tid)
{
	e->tmp[tid] = e->wall[tid];
	/*
	if (e->wall[tid].top >= e->prev_wall[tid].top && e->wall[tid].bottom <= e->prev_wall[tid].bottom)
	{
		printf("case 1: inside of prev\n");
		printf("top %d ptop %d bottom %d pbottom %d\n", e->wall[tid].top, e->prev_wall[tid].top, e->wall[tid].bottom, e->prev_wall[tid].bottom);
		return (1);
	}
	if (e->wall[tid].top <= e->prev_wall[tid].top && e->wall[tid].bottom >= e->prev_wall[tid].bottom)
	{
		printf("case 0: bigger than prev\n");
		printf("top %d ptop %d bottom %d pbottom %d\n", e->wall[tid].top, e->prev_wall[tid].top, e->wall[tid].bottom, e->prev_wall[tid].bottom);
		return (1);
	}
	if (e->wall[tid].bottom < e->prev_wall[tid].top && e->wall[tid].bottom < e->prev_wall[tid].bottom)
	{
		printf("case 2: fully above prev\n");
		printf("top %d ptop %d bottom %d pbottom %d\n", e->wall[tid].top, e->prev_wall[tid].top, e->wall[tid].bottom, e->prev_wall[tid].bottom);
		return (0);
	}
	if (e->wall[tid].top > e->prev_wall[tid].bottom && e->wall[tid].bottom > e->prev_wall[tid].bottom)
	{
		printf("case 3: fully below prev\n");
		printf("top %d ptop %d bottom %d pbottom %d\n", e->wall[tid].top, e->prev_wall[tid].top, e->wall[tid].bottom, e->prev_wall[tid].bottom);
		return (0);
	}
	if (e->wall[tid].bottom > e->prev_wall[tid].top && e->wall[tid].top < e->prev_wall[tid].top)
	{
		printf("case 4: we can see the top part\n");
		printf("top %d ptop %d bottom %d pbottom %d\n", e->wall[tid].top, e->prev_wall[tid].top, e->wall[tid].bottom, e->prev_wall[tid].bottom);
		e->wall[tid].bottom = e->prev_wall[tid].top;
		return (0);
	}
	else if (e->wall[tid].top < e->prev_wall[tid].bottom)
	{
		printf("case 5: we can see the bottom part\n");
		printf("top %d ptop %d bottom %d pbottom %d\n", e->wall[tid].top, e->prev_wall[tid].top, e->wall[tid].bottom, e->prev_wall[tid].bottom);
		e->wall[tid].top = e->prev_wall[tid].bottom;
		//offset pb here // maybe save the diff or do that somewhere else
		return (0);
	}
	if (e->wall[tid].top >= e->prev_wall[tid].top)
		return (1);
	printf("case unknown, top %d ptop %d bottom %d pbottom %d\n", e->wall[tid].top, e->prev_wall[tid].top, e->wall[tid].bottom, e->prev_wall[tid].bottom);
	*/
	return (0);
}

int			get_wall_height(t_env *e, int column, int tid)
{
	if (!e->ray[tid].hor.skip && !e->ray[tid].vert.skip)
		return (0);
	e->wall[tid].tex = (e->ray[tid].hor.dist <= e->ray[tid].vert.dist) ? 0 : 1;
	e->wall[tid].dist = (e->ray[tid].hor.dist <= e->ray[tid].vert.dist) ? \
		e->ray[tid].hor.dist : e->ray[tid].vert.dist;
	e->wall[tid].texture_x = (e->ray[tid].hor.dist <= e->ray[tid].vert.dist) \
	? (Uint32)(e->ray[tid].hor.x) % TILE_SIZE : (Uint32)(e->ray[tid].vert.y) \
	% TILE_SIZE;
	e->wall[tid].tex = (e->ray[tid].hor.dist <= e->ray[tid].vert.dist) \
					   ? e->ray[tid].hor.tex : e->ray[tid].vert.tex;
	e->wall[tid].dist *= e->fisheye_table[column];
	e->wall[tid].dist < 0.1 ? e->wall[tid].dist = 0.1 : 0;
	e->wall[tid].hor = (e->ray[tid].hor.dist <= e->ray[tid].vert.dist) ? true : false;
	if (e->wall[tid].dist <= 0 || e->wall[tid].dist == 2147483647)
		e->wall[tid].bottom = 0;
	else
	{
		e->wall[tid].height = WALL_HEIGHT * e->player.plane_dist \
		/ e->wall[tid].dist;
		e->wall[tid].bottom = (ceil((e->player.plane_dist / e->wall[tid].dist) \
		* e->player.height + e->horizon)) - e->wall[tid].height * e->ray[tid].layer;
		e->wall_heights[e->ray[tid].layer][column] = e->wall[tid].height;
		e->wall[tid].top = e->wall[tid].bottom - (int)e->wall[tid].height;
		if (e->prev_wall[tid].is_prev)
			if (crop_next_wall(e, tid))
				return (0);
	}
	return (1);
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
	y = e->wall[tid].top - 1;
	while (++y < e->wall[tid].bottom + 1)
	{
		color = e->files.wall[e->wall[tid].tex][((int)texture_y << e->tile_shift) + e->wall[tid].texture_x];
		if (e->wall[tid].hor)
		{
			if (e->data.map[DLIGHT][e->ray[tid].layer][e->ray[tid].hor.map.y][e->ray[tid].hor.map.x])
				color = (color >> 1) & 8355711;
		}
		else
		{
			if (e->data.map[DLIGHT][e->ray[tid].layer][e->ray[tid].vert.map.y][e->ray[tid].vert.map.x])
				color = (color >> 1) & 8355711;
		}
		e->buff[y * WIN_W + column] = color;
		texture_y += ratio;
		if (texture_y >= TILE_SIZE)
			break ;
	}
}
