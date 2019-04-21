/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:49:07 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/13 23:59:10 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

static void				init_grid_var(t_env *e)
{
	e->grid.grid_rect.x = PANEL + MARGIN;
	e->grid.grid_rect.y = MARGIN;
	e->grid.grid_rect.w = WIN_W - MARGIN;
	e->grid.grid_rect.h = WIN_H - MARGIN;
	e->grid.mouseposgridx = -1;
	e->grid.mouseposgridy = -1;
	if (e->parsed)
	{
		e->grid.x = e->data.max_x;
		e->grid.y = e->data.tier_size;
	}
	else
	{
		e->grid.x = 10;
		e->grid.y = 10;
	}
}

static void				init_draw_var(t_env *e)
{
	int					i;

	i = -1;
	e->wellcome_screen = 1;
	e->panel_index = 0;
	e->sprite_nb = 100;
	e->f[0] = draw_panel_wall;
	e->f[1] = draw_panel_floor;
	e->f[2] = draw_panel_sprite;
	e->f[3] = draw_panel_light;
	e->f[4] = draw_panel_event;
	while (++i < 4)
	{
		e->draw[i].white.a = 0;
		e->draw[i].white.r = 255;
		e->draw[i].white.g = 255;
		e->draw[i].white.b = 255;
		e->draw[i].text = NULL;
		if (i == 0 && !(e->draw[i].font = TTF_OpenFont("font/BEBAS.TTF", 160)))
			exit_error(2, ERR_2);
		if (i != 0 && !(e->draw[i].font = TTF_OpenFont("font/BEBAS.TTF", 28)))
			exit_error(2, ERR_2);
	}
}

static void				init_sdl(t_env *e)
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	if (!(e->window.win = SDL_CreateWindow("Doom_Editor", \
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, \
				SDL_WINDOW_RESIZABLE)))
		exit_error(1, ERR_7);
	if (!(e->window.screen = SDL_GetWindowSurface(e->window.win)))
		exit_error(1, ERR_7);
	SDL_SetWindowResizable(e->window.win, SDL_FALSE);
	e->buff = (Uint32 *)e->window.screen->pixels;
}

void					init(t_env *e)
{
	ft_memset(e->tab, 0, sizeof(e->tab));
	init_sdl(e);
	init_draw_var(e);
	init_grid_var(e);
	init_var_texture(e);
}
