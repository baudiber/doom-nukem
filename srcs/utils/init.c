/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:38 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/26 12:23:45 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double					angle_to_rad(int angle, t_env *e)
{
	return ((angle * LM_PI) / e->angle.a_180);
}

double					angle_to_deg(int angle, t_env *e)
{
	return ((angle * e->angle.a_180) / LM_PI);
}

void					init_sdl(t_env *e)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_ShowCursor(SDL_DISABLE);
	TTF_Init();
	if (!(e->win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED, \
					SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, \
					SDL_WINDOW_INPUT_GRABBED)))
		exit_error(8);
	if (!(e->screen = SDL_GetWindowSurface(e->win)))
		exit_error(8);
	//SDL_SetWindowResizable(e->win, SDL_FALSE);
	e->buff = (Uint32 *)e->screen->pixels;
}

void					init_player(t_env *e)
{
	e->player.pos.x = (e->data.pos_x + 0.5) * TILE_SIZE;
	e->player.pos.y = (e->data.pos_y + 0.5) * TILE_SIZE;
	e->render_limit = (WIN_H / 4) * 3.2;
	e->ui.ui_size = WIN_H - e->render_limit;
	e->horizon = e->render_limit / 2;
	e->max_speed = TILE_SIZE / 15;
	e->player.height = WALL_HEIGHT / 2;
	e->player.plane_dist = (int)((WIN_W / 2) / tan((FOV / 2.0) * LM_PI / 180));
	e->player.pace = 90;
}
