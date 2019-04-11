/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:56:03 by roddavid          #+#    #+#             */
/*   Updated: 2019/03/29 17:45:08 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		mouse_menu_options_2(t_env *e)
{
	if (e->menu.mute == 0)
	{
		e->menu.mute = 1;
		e->menu.i_img = 9;
		Mix_Volume(-1, 128 * 0);
		Mix_PauseMusic();
	}
	else if (e->menu.mute == 1)
	{
		e->menu.i_img = e->menu.save_img2;
		e->menu.mute = 0;
		Mix_Volume(-1, 128 * 0.05);
		Mix_ResumeMusic();
	}
}

void		mouse_menu_options(t_env *e, int x, int y, SDL_Event ev)
{
	int save;

	if (e->menu.mute == 0)
		e->menu.save_img2 = e->menu.i_img;
	e->menu.i_img = e->menu.save_img;
	save = e->menu.i_img;
	if ((x >= 390 && x <= 880) && (y >= 400 && y <= 450) \
	&& ev.button.button == SDL_BUTTON_LEFT && ev.button.state == SDL_PRESSED)
		mouse_menu_options_2(e);
	ft_slider(e, x, y, ev);
	e->menu.save_img = e->menu.i_img;
}

void		ft_menu_options_2(t_env *e, SDL_Event ev, int x, int y)
{
	if (ev.type == SDL_QUIT || (ev.key.keysym.sym == SDLK_ESCAPE \
		&& ev.type == SDL_KEYDOWN))
	{
		e->menu.i_img = 1;
		e->menu.check_options = 1;
	}
	if ((x >= 1 && x <= 70) && (y >= 1 && y <= 60) \
		&& ev.button.button == SDL_BUTTON_LEFT)
	{
		e->menu.i_img = 1;
		e->menu.check_options = 1;
	}
}

void		ft_menu_options(t_env *e)
{
	int			x;
	int			y;
	SDL_Event	ev;

	e->menu.check_options = 0;
	while (e->menu.check_options != 1)
	{
		SDL_GetMouseState(&x, &y);
		SDL_UpdateWindowSurface(e->win);
		SDL_BlitSurface(e->menu.image[e->menu.i_img], NULL, \
			e->screen, NULL);
		while (SDL_PollEvent(&ev))
		{
			mouse_menu_options(e, x, y, ev);
			ft_menu_options_2(e, ev, x, y);
		}
	}
}