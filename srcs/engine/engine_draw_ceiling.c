/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_draw_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:28:48 by baudiber          #+#    #+#             */
/*   Updated: 2019/03/31 17:37:10 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	draw_ceilings(t_env *e, int x, int tid)
{
	t_floor		ceil;
	int			y;

	ft_bzero(&ceil, sizeof(t_floor));
	if (e->ray[tid].layer > 0)
		return ;
	y = e->wall[tid].top;
	if (y <= 0)
		return;
	while (--y > 0)
	{
		ceil.dist = (TILE_SIZE - (double)e->player.height) / (e->horizon - y) \
	* (double)e->player.plane_dist;
		ceil.dist *= e->i_fisheye_table[x];
		ceil.y = ceilf(ceil.dist * e->sin_table[e->ray[tid].angle]);
		ceil.x = ceilf(ceil.dist * e->cos_table[e->ray[tid].angle]);
		ceil.x += e->player.pos.x;
		ceil.y += e->player.pos.y;
		ceil.map.x = ceil.x >> e->tile_shift;
		ceil.map.y = ceil.y >> e->tile_shift;
		if (ray_is_in_the_map(ceil.map.x, ceil.map.y, e))
		{
			if (e->data.map[0][e->ray[tid].layer + 1][ceil.map.y][ceil.map.x])
			{
				ceil.y = ceil.y % TILE_SIZE;
				ceil.x = ceil.x % TILE_SIZE;
				e->buff[y * WIN_W + x] = e->files.floor[1][(ceil.y << e->tile_shift) + ceil.x];
			}
		}
	}
}
