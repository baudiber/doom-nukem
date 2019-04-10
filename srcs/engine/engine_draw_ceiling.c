/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_draw_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:28:48 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/10 20:04:55 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	draw_ceilings(t_env *e, int x, int tid)
{
	t_floor		ceil;
	int			y;

	ft_bzero(&ceil, sizeof(t_floor));
	if (e->player.floor > e->ray[tid].layer)
		return ;
	if (e->ray[tid].layer == (int)e->floor_nb - 1)
		return ;
	y = e->horizon;
	if (y <= 0)
		return;
	if (y > WIN_H)
		y = WIN_H;
	while (--y > 0)
	{
		ceil.dist = ((double)(TILE_SIZE * (e->ray[tid].layer + 1)) - (e->player.height)) / (e->horizon - y) * (double)e->player.plane_dist;
		ceil.dist *= e->i_fisheye_table[x];
		ceil.y = ceilf(ceil.dist * e->sin_table[e->ray[tid].angle]);
		ceil.x = ceilf(ceil.dist * e->cos_table[e->ray[tid].angle]);
		ceil.x += e->player.pos.x;
		ceil.y += e->player.pos.y;
		ceil.map.x = ceil.x >> e->tile_shift;
		ceil.map.y = ceil.y >> e->tile_shift;
		if (ray_is_in_the_map(ceil.map, e))
		{
			if (e->data.map[DWALL][e->ray[tid].layer + 1][ceil.map.y][ceil.map.x]
			&& !e->data.map[DWALL][e->ray[tid].layer][ceil.map.y][ceil.map.x])
			{
				ceil.y = ceil.y % TILE_SIZE;
				ceil.x = ceil.x % TILE_SIZE;
				e->buff[y * WIN_W + x] = e->files.floor[1][(ceil.y << e->tile_shift) + ceil.x];
			}
		}
	}
}
