/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <baudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:51:51 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/13 19:08:17 by baudiber         ###   ########.fr       */
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
	y_offset = 0;
	while (++y < (int)info->y_end)
	{
		x_offset = 0;
		x = (int)info->x_start;
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

void			display_skybox(t_env *e)
{
	SDL_Rect	temp;

	temp = e->draw.sky_rect;
	SDL_BlitSurface(e->files.skybox, NULL, e->screen, &temp);
	temp = e->draw.sky_rect2;
	SDL_BlitSurface(e->files.skybox, NULL, e->screen, &temp);
}

void			moving_rects(t_env *e)
{
	e->draw.sky_rect.x = (int)e->draw.skybox_x;
	e->draw.sky_rect.y = e->draw.skybox_y;
	e->draw.sky_rect.w = e->files.skybox->w;
	e->draw.sky_rect.h = e->files.skybox->h;
	e->draw.sky_rect2.x = (int)e->draw.skybox_x - 1226;
	e->draw.sky_rect2.y = e->draw.skybox_y;
	e->draw.sky_rect2.w = e->files.skybox->w;
	e->draw.sky_rect2.h = e->files.skybox->h;
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
