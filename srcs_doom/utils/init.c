/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:38 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/13 15:47:07 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

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
	TTF_Init();
	if (!(e->win = SDL_CreateWindow("Doom-nukem", SDL_WINDOWPOS_CENTERED, \
					SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, \
					SDL_WINDOW_INPUT_GRABBED)))
		exit_error(17, ERR_7);
	if (!(e->screen = SDL_GetWindowSurface(e->win)))
		exit_error(17, ERR_7);
	if (!(SDL_SetRelativeMouseMode(SDL_TRUE) == 0))
		exit_error(17, ERR_7);
	e->buff = (Uint32 *)e->screen->pixels;
}

void					init_player(t_env *e)
{
	e->player.pos.x = (e->data.pos_x + 0.5) * TILE_SIZE;
	e->player.pos.y = (e->data.pos_y + 0.5) * TILE_SIZE;
	e->player.win = false;
	e->player.moving = false;
	e->render_limit = (WIN_H / 4) * 3.2;
	e->ui.ui_size = WIN_H - e->render_limit;
	e->horizon = e->render_limit / 2;
	e->max_speed = TILE_SIZE / 25;
	e->player.height = WALL_HEIGHT / 2 + e->data.pos_z * WALL_HEIGHT;
	e->player.plane_dist = (int)((WIN_W / 2) / tan((FOV / 2.0) * LM_PI / 180));
	e->player.pace = 90;
	e->player.angle = e->angle.a_270 + 1;
	e->floor_nb = e->data.tier_ind + 1;
	e->player.hp = 100;
}
