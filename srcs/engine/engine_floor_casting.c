/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_floor_casting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:36 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/23 16:06:51 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	floor_casting(t_env *e, int column, int tid)
{
	t_floor		floor;
	int			y;

	ft_bzero(&floor, sizeof(t_floor));
	y = e->wall[tid].bottom - 1;
	y = (y < 0) ? -1 : y;
	while (++y < e->render_limit)
	{
		floor.dist = (double)e->player.height / (y - e->horizon) \
	* (double)e->player.plane_dist;
		floor.dist *= e->i_fisheye_table[column];
		floor.y = (int)(floor.dist * e->sin_table[e->ray[tid].angle]);
		floor.x = (int)(floor.dist * e->cos_table[e->ray[tid].angle]);
		floor.x += e->player.pos.x;
		floor.y += e->player.pos.y;
		floor.map.x = floor.x >> e->tile_shift;
		floor.map.y = floor.y >> e->tile_shift;
		if (ray_is_in_the_map(floor.map.x, floor.map.y, e))
		{
			floor.y = floor.y % TILE_SIZE;
			floor.x = floor.x % TILE_SIZE;
			e->buff[y * WIN_W + column] = e->files.floor[(floor.y \
					<< e->tile_shift) + floor.x];
		}
	}
}
