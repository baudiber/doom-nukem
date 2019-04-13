/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:37 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/13 01:54:20 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			get_player_floor(t_env *e)
{
	e->player.floor = e->player.height >> e->tile_shift;
	e->player.map.x = (int)e->player.pos.x >> e->tile_shift;
	e->player.map.y = (int)e->player.pos.y >> e->tile_shift;
	if (ray_is_in_the_map(e->player.map, e))
		floor_is_lava(e);
}

bool			ray_is_in_the_map(t_point_int pt, t_env *e)
{
	if (pt.x < 0 || pt.x >= e->data.max_x || pt.y < 0 || pt.y >= e->data.max_y)
		return (false);
	return (true);
}

void			angle_overflow(int *angle, t_env *e)
{
	if (*angle >= e->angle.a_360)
		*angle -= e->angle.a_360;
	else if (*angle < 0)
		*angle += e->angle.a_360;
}

static void		cast_rays(t_env *e, int tid)
{
	int		column;

	column = e->thread_col_size * tid - 1;
	while (++column < e->ray[tid].max_column)
	{
		if (column >= WIN_W)
			break ;
		get_horizontal_hit(e, tid);
		get_vertical_hit(e, tid);
		e->prev_wall[tid].is_prev = false;
		draw_floor(e, column, tid);
		draw_ceilings(e, column, tid);
		double_dda(e, tid, column);
		e->ray[tid].angle++;
		if (e->ray[tid].angle >= e->angle.a_360)
			e->ray[tid].angle -= e->angle.a_360;
	}
}

void			*raycaster_mt(void *arg)
{
	t_env		*e;
	int			tid;
	Uint32		i;

	e = (t_env *)arg;
	tid = thread_nb(e);
	e->ray[tid].max_column = e->thread_col_size * (tid + 1);
	i = 0;
	while (i < e->floor_nb)
	{
		e->ray[tid].layer = e->floor_order[i];
		e->ray[tid].angle = (e->player.angle - e->angle.a_half_fov) \
			+ e->thread_col_size * tid;
		angle_overflow(&e->ray[tid].angle, e);
		cast_rays(e, tid);
		draw_sprites(e, e->ray[tid].max_column, tid);
		i++;
	}
	pthread_exit(0);
}
