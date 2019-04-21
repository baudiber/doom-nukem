/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_draw_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <baudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:28:48 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/14 00:16:16 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	cast_ceiling(t_floor *ceil, int tid, int y, int x)
{
	t_env	*e;

	e = call();
	ceil->dist = (double)TILE_SIZE * (e->ray[tid].layer + 1) - e->player.height;
	ceil->dist /= (double)e->horizon - y;
	ceil->dist *= (double)e->player.plane_dist;
	ceil->dist *= e->i_fisheye_table[x];
	ceil->y = ceilf(ceil->dist * e->sin_table[e->ray[tid].angle]);
	ceil->x = ceilf(ceil->dist * e->cos_table[e->ray[tid].angle]);
	ceil->x += e->player.pos.x;
	ceil->y += e->player.pos.y;
	ceil->map.x = ceil->x >> e->tile_shift;
	ceil->map.y = ceil->y >> e->tile_shift;
}

void	draw_ceilings(t_env *e, int x, int tid)
{
	t_floor		ceil;
	int			y;

	ft_bzero(&ceil, sizeof(t_floor));
	if (e->player.floor > e->ray[tid].layer \
		|| (e->ray[tid].layer == (int)e->floor_nb - 1))
		return ;
	y = e->horizon;
	y = (y > WIN_H) ? WIN_H : y;
	while (--y >= 0)
	{
		cast_ceiling(&ceil, tid, y, x);
		if (ray_is_in_the_map(ceil.map, e))
		{
			if (e->data.map[DWALL][e->ray[tid].layer + 1]\
				[ceil.map.y][ceil.map.x] && !e->data.map[DWALL]\
				[e->ray[tid].layer][ceil.map.y][ceil.map.x])
			{
				ceil.y = ceil.y % TILE_SIZE;
				ceil.x = ceil.x % TILE_SIZE;
				e->buff[y * WIN_W + x] = e->files.floor[5]\
					[(ceil.y << e->tile_shift) + ceil.x];
			}
		}
	}
}
