/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_floor_casting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:36 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/09 23:50:08 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	floor_casting(t_env *e, int column, int tid)
{
	t_floor		floor;
	int			y;
	int			tex;
	int			color;

	if (e->player.floor < e->ray[tid].layer)
		return ;
	ft_bzero(&floor, sizeof(t_floor));
//	y = e->horizon;
	y = (e->horizon < 0) ? -1 : e->horizon;
	while (++y < e->render_limit)
	{
		floor.dist = ((double)e->player.height - TILE_SIZE * e->ray[tid].layer + 1 ) / (y - e->horizon) \
	* (double)e->player.plane_dist;
		floor.dist *= e->i_fisheye_table[column];
		//if (e->wall_dist[e->ray[tid].layer][column] > 0 && floor.dist > (e->wall_dist[e->ray[tid].layer][column] * 10))
		//	return ;
		floor.y = (int)(floor.dist * e->sin_table[e->ray[tid].angle]);
		floor.x = (int)(floor.dist * e->cos_table[e->ray[tid].angle]);
		floor.x += e->player.pos.x;
		floor.y += e->player.pos.y;
		floor.map.x = floor.x >> e->tile_shift;
		floor.map.y = floor.y >> e->tile_shift;
		if (ray_is_in_the_map(floor.map, e))
		{
			if (e->ray[tid].layer > 0)
			{
				if (!e->data.map[DWALL][e->ray[tid].layer - 1][floor.map.y][floor.map.x]
				 || e->data.map[DWALL][e->ray[tid].layer][floor.map.y][floor.map.x])
					continue ;
			}
			tex = e->data.map[DFLOOR][e->ray[tid].layer][floor.map.y][floor.map.x];
			floor.y = floor.y % TILE_SIZE;
			floor.x = floor.x % TILE_SIZE;
			color = e->files.floor[tex][(floor.y << e->tile_shift) + floor.x];
			if (e->data.map[DLIGHT][e->ray[tid].layer][floor.map.y][floor.map.x])
				color = (color >> 1) & 8355711;
			e->buff[y * WIN_W + column] = color;
		}
	}
}
