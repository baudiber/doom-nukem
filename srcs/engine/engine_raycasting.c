/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:37 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/04 19:31:48 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	get_player_floor(t_env *e)
{
	e->player.floor = e->player.height >> e->tile_shift;
}

void	angle_overflow(int *angle, t_env *e)
{
	if (*angle >= e->angle.a_360)
		*angle -= e->angle.a_360;
	else if (*angle < 0)
		*angle += e->angle.a_360;
}

void	*raycaster_mt(void *arg)
{
	int			column;
	t_env		*e;
	int			tid;

	e = (t_env *)arg;
	tid = thread_nb(e);
	get_player_floor(e);
	e->ray[tid].layer = 1;
	while (e->ray[tid].layer >= 0)
	{
		e->ray[tid].angle = (e->player.angle - e->angle.a_half_fov) \
							+ e->thread_col_size * tid;
		angle_overflow(&e->ray[tid].angle, e);
		column = e->thread_col_size * tid - 1;
		while (++column < (e->thread_col_size * (tid + 1)))
		{
			if (column >= WIN_W)
				break ;

			get_horizontal_hit(e, tid);
			get_vertical_hit(e, tid);
			e->ray[tid].hor.in_map = true;
			e->ray[tid].vert.in_map = true;
			e->ray[tid].vert.dist = 0;
			e->ray[tid].hor.dist = 0;
			e->prev_wall[tid].is_prev = false;
			while (e->ray[tid].vert.in_map || e->ray[tid].hor.in_map)
			{
				if (e->ray[tid].hor.in_map && e->ray[tid].hor.dist != 2147483647)
					horizontal_dda(e, tid);
				if (e->ray[tid].vert.in_map && e->ray[tid].vert.dist != 2147483647)
					vertical_dda(e, tid);
				if (!e->ray[tid].vert.in_map && !e->ray[tid].hor.in_map)
					break;
				if (get_wall_height(e, column, tid))
					draw_wall(e, column, tid);
				if (e->prev_wall[tid].is_prev) 
					e->prev_wall[tid] = e->tmp[tid];
				else 
					e->prev_wall[tid] = e->wall[tid];
				e->prev_wall[tid].is_prev = true;
				e->ray[tid].hor.x += e->ray[tid].hor.next_x;
				e->ray[tid].hor.y += e->ray[tid].hor.next_y;
				e->ray[tid].vert.y += e->ray[tid].vert.next_y;
				e->ray[tid].vert.x += e->ray[tid].vert.next_x;
				e->ray[tid].vert.skip = false;
				e->ray[tid].hor.skip = false;
			}
			//floor_casting(e, column, tid);
			//draw_ceilings(e, column, tid);
			e->ray[tid].angle++;
			if (e->ray[tid].angle >= e->angle.a_360)
				e->ray[tid].angle -= e->angle.a_360;
		}
		e->ray[tid].layer--;
	}
	pthread_exit(0);
}
