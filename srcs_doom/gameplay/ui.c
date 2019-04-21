/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <baudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:51:51 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/13 22:17:40 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			draw_scaled(t_env *e, t_draw_scaled *info)
{
	int			x;
	int			y;
	float		x_offset;
	float		y_offset;
	Uint32		color;

	y = (int)info->y_start;
	y = y < 0 ? 0 : y;
	y_offset = 0;
	while (++y < (int)info->y_end)
	{
		x_offset = 0;
		x = (int)info->x_start;
		x = x < 0 ? 0 : x;
		while (++x < (int)info->x_end)
		{
			color = info->buffer[info->index][(int)y_offset \
				* info->w + (int)x_offset];
			if (color ^ 0xFF00FFFF)
				e->buff[y * WIN_W + x] = color;
			x_offset += info->x_ratio;
		}
		y_offset += info->y_ratio;
	}
}

void			draw_crosshair(t_env *e)
{
	int		x;
	int		y;
	int		end;

	y = (e->render_limit * 0.5 - 5);
	end = y + 8;
	x = WIN_W * 0.5;
	while (++y < end)
		e->buff[y * WIN_W + x] = 0xffffff;
	y -= 4;
	y *= WIN_W;
	x -= 4;
	end = x + 8;
	while (++x < end)
		e->buff[y + x] = 0xffffff;
}

void			draw_ui(t_env *e)
{
	draw_scaled(e, &e->ui_info);
	draw_crosshair(e);
	bob(e);
	draw_scaled(e, &e->face_info);
	draw_scaled(e, &e->inv_info);
	draw_life(e);
	if (e->ui.weapon == 2)
		draw_scaled(e, &e->shotgun_info);
	else
		draw_scaled(e, &e->pistol_info);
	e->ui.trumpet ? draw_scaled(e, &e->trumpet_info) : 0;
}
