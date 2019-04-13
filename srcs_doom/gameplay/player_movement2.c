/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 00:55:50 by gagonzal          #+#    #+#             */
/*   Updated: 2019/04/14 00:12:24 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

bool			is_blocked(t_env *e, t_point *new_pos, int y)
{
	t_point_int		pt;

	pt.x = (int)new_pos->x >> e->tile_shift;
	pt.y = (int)new_pos->y >> e->tile_shift;
	if (!ray_is_in_the_map(pt, e))
		return (false);
	if (y)
	{
		if (e->data.map[DWALL][e->player.floor][pt.y][e->player.map.x])
			return (true);
	}
	else if (!y)
	{
		if (e->data.map[DWALL][e->player.floor][e->player.map.y][pt.x])
			return (true);
	}
	return (false);
}

void			collision(t_env *e, t_point *new_pos)
{
	if (!is_blocked(e, new_pos, 0))
	{
		e->player.pos.x = new_pos->x;
		e->player.pace += 3;
	}
	if (!is_blocked(e, new_pos, 1))
	{
		e->player.pos.y = new_pos->y;
		e->player.pace += 3;
	}
	if (e->player.pace > 360)
		e->player.pace -= 360;
}

int				get_ceil_height(t_env *e)
{
	int i;
	int ceil_height;

	ceil_height = 0;
	i = 1;
	while (i < (int)e->floor_nb)
	{
		if (e->data.map[DWALL][e->player.floor + i][e->player.map.y]\
			[e->player.map.x])
		{
			ceil_height = (e->player.floor + 1) * TILE_SIZE;
			return (ceil_height);
		}
		i++;
	}
	return (((int)e->floor_nb) * TILE_SIZE);
}

void			get_floor_dist(t_env *e)
{
	if (e->player.map.x && e->player.map.y && e->player.floor && \
		e->data.map[DWALL][e->player.floor - 1][e->player.map.y]\
		[e->player.map.x])
		e->player.dist_to_floor = e->player.floor * TILE_SIZE + WALL_HEIGHT / 2;
	else
		e->player.dist_to_floor = TILE_SIZE / 2;
}

void			jump_anim(t_env *e)
{
	static double	jump_time;
	int				ceil_height;

	ceil_height = get_ceil_height(e);
	if (e->player_state & IS_FLY)
		return ;
	if ((e->player_state & IS_JUMPING) && e->data.map[DWALL]\
		[e->player.floor + 1][e->player.map.y][e->player.map.x])
	{
		if (e->player.height >= ceil_height - 20)
			e->player_state &= (0 << 2);
	}
	if ((e->player_state & IS_JUMPING) && jump_time <= 0.28)
	{
		jump_time += e->time.frame_time;
		if (e->player.height < ceil_height)
			e->player.height += (e->max_speed + 3) * e->time.delta_time;
	}
	else
	{
		e->player_state &= (0 << 2);
		e->player_state |= IS_FALLING;
		jump_time = 0;
	}
}
