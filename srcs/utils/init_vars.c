/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:54:00 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/26 10:38:17 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void				checking(t_env *e, int i)
{
	if (i >= e->angle.a_90 && i < e->angle.a_270)
	{
		e->x_step_table[i] = TILE_SIZE / e->tan_table[i];
		if (e->x_step_table[i] > 0)
			e->x_step_table[i] = -e->x_step_table[i];
	}
	else
	{
		e->x_step_table[i] = TILE_SIZE / e->tan_table[i];
		if (e->x_step_table[i] < 0)
			e->x_step_table[i] = -e->x_step_table[i];
	}
	if (i >= 0 && i < e->angle.a_180)
	{
		e->y_step_table[i] = TILE_SIZE * e->tan_table[i];
		if (e->y_step_table[i] < 0)
			e->y_step_table[i] = -e->y_step_table[i];
	}
	else
	{
		e->y_step_table[i] = TILE_SIZE * e->tan_table[i];
		if (e->y_step_table[i] > 0)
			e->y_step_table[i] = -e->y_step_table[i];
	}
}

static void				set_table(t_env *e, int i, double radian)
{
	radian = angle_to_rad(i, e) + 0.0001;
	e->sin_table[i] = sin(radian);
	e->i_sin_table[i] = 1.0 / e->sin_table[i];
	e->cos_table[i] = cos(radian);
	e->i_cos_table[i] = 1.0 / e->cos_table[i];
	e->tan_table[i] = tan(radian);
	e->i_tan_table[i] = 1.0 / e->tan_table[i];
	checking(e, i);
}

static void				set_angle(t_env *e)
{
	e->thread_col_size = WIN_W / MAX_THREADS;
	e->time.max_time = 1.0 / MAX_FPS;
	e->angle.a_5 = ((double)WIN_W / FOV) * 5;
	e->angle.a_2 = ((double)WIN_W / FOV) * 2;
	e->angle.a_half_fov = ((double)WIN_W / 2);
	e->angle.a_40 = ((double)WIN_W / FOV) * 40;
	e->angle.a_90 = ((double)WIN_W / FOV) * 90;
	e->angle.a_140 = ((double)WIN_W / FOV) * 140;
	e->angle.a_180 = ((double)WIN_W / FOV) * 180;
	e->angle.a_270 = ((double)WIN_W / FOV) * 270;
	e->angle.a_360 = ((double)WIN_W / FOV) * 360;
}

void					init_vars(t_env *e)
{
	int			i;
	double		radian;

	radian = 0.0;
	e->tile_shift = (TILE_SIZE == 64) ? 6 : e->tile_shift;
	e->tile_shift = (TILE_SIZE == 128) ? 7 : e->tile_shift;
	e->tile_shift = (TILE_SIZE == 256) ? 8 : e->tile_shift;
	if (TILE_SIZE != 64 && TILE_SIZE != 128 && TILE_SIZE != 256)
		exit_error(12);
	set_angle(e);
	i = -1;
	while (++i < e->angle.a_360)
		set_table(e, i, radian);
	i = -e->angle.a_half_fov;
	while (i < e->angle.a_half_fov)
	{
		radian = angle_to_rad(i, e);
		e->fisheye_table[i + e->angle.a_half_fov] = cos(radian);
		e->i_fisheye_table[i + e->angle.a_half_fov] = 1.0 / cos(radian);
		i++;
	}
}
