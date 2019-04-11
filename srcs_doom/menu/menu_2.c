/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 07:09:19 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/11 21:49:36 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		load_screen_2(t_env *e, int check, SDL_Event ev)
{
	check = 0;
	while (check != 1)
	{
		gif_load_screen(e);
		check++;
		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT || (ev.key.keysym.sym == SDLK_ESCAPE \
				&& ev.type == SDL_KEYDOWN))
			{
				clean_up(e);
				exit(0);
			}
		}
	}
}

static void		mouse_menu_2(t_env *e, int y, SDL_Event ev)
{
	if (y >= 406 && y <= 456)
	{
		e->menu.i_img = 1;
		if (ev.button.button == SDL_BUTTON_LEFT \
			&& ev.button.state == SDL_PRESSED)
		{
			ev.button.button = SDL_BUTTON_RIGHT;
			ft_menu_options(e);
		}
	}
	if (y >= 457 && y <= 507)
	{
		e->menu.i_img = 2;
		if (ev.button.button == SDL_BUTTON_LEFT)
		{
			clean_up(e);
			exit(0);
		}
	}
}

static void			ft_menu_2_2(t_env *e, SDL_Event ev)
{
	if (e->menu.i_img == 0)
		if (ev.key.keysym.sym == '\r' && ev.type == SDL_KEYDOWN)
			e->menu.check = 1;
	if (e->menu.i_img == 1)
		if (ev.key.keysym.sym == '\r' && ev.type == SDL_KEYDOWN)
			ft_menu_options(e);
	if (e->menu.i_img == 2)
		if (ev.key.keysym.sym == '\r' && ev.type == SDL_KEYDOWN)
		{
			clean_up(e);
			exit(0);
		}
}

static void			ft_menu_3(t_env *e, SDL_Event ev, int *x, int *y)
{
	SDL_GetMouseState(x, y);
	SDL_UpdateWindowSurface(e->win);
	SDL_BlitSurface(e->menu.image[e->menu.i_img], NULL, \
		e->screen, NULL);
	if ((ev.key.keysym.sym == SDLK_ESCAPE && ev.type == SDL_KEYDOWN))
		e->menu.check = 1;
}

void	ft_menu_2(t_env *e, SDL_Event ev)
{
	if ((ev.key.keysym.sym == 's' || ev.key.keysym.sym == SDLK_DOWN) \
	&& ev.type == SDL_KEYDOWN)
	{
		Mix_PlayChannel(-1, e->sound.sound1, 0);
		if (e->menu.i_img < 2)
			e->menu.i_img++;
		else if (e->menu.i_img == 2)
			e->menu.i_img = 0;
	}
	if ((ev.key.keysym.sym == 'w' || ev.key.keysym.sym == SDLK_UP) \
	&& ev.type == SDL_KEYDOWN)
	{
		Mix_PlayChannel(-1, e->sound.sound1, 0);
		if (e->menu.i_img > 0)
			e->menu.i_img--;
		else if (e->menu.i_img == 0)
			e->menu.i_img = 2;
	}
	ft_menu_2_2(e, ev);
}
