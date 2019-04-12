/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:12:20 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/13 01:00:44 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void			refresh_gif(t_env *e, int i)
{
	SDL_UpdateWindowSurface(e->win);
	SDL_BlitSurface(e->menu.image[i], NULL, e->screen, NULL);
	SDL_Delay(150);
}

void				gif_load_screen(t_env *e)
{
	refresh_gif(e, 10);
	refresh_gif(e, 11);
	refresh_gif(e, 12);
	refresh_gif(e, 13);
	refresh_gif(e, 14);
	refresh_gif(e, 15);
	Mix_PlayChannel(-1, e->sound.sound1, 0);
	refresh_gif(e, 16);
	refresh_gif(e, 17);
	refresh_gif(e, 16);
	refresh_gif(e, 15);
	refresh_gif(e, 14);
	refresh_gif(e, 13);
	refresh_gif(e, 12);
	refresh_gif(e, 11);
}

void				load_screen(t_env *e)
{
	SDL_Event		ev;
	int				check;

	sleep(1);
	check = 0;
	while (check != 1)
	{
		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT || (ev.key.keysym.sym == SDLK_ESCAPE \
				&& ev.type == SDL_KEYDOWN))
			{
				clean_up(e);
				exit(0);
			}
		}
		gif_load_screen(e);
		check++;
	}
}

void				mouse_menu(t_env *e, int x, int y, SDL_Event ev)
{
	int				save;

	save = e->menu.i_img;
	if (x > 270 && x < 520)
	{
		if (y >= 355 && y <= 405)
		{
			e->menu.i_img = 0;
			if (ev.button.button == SDL_BUTTON_LEFT)
			{
				restart(e);
				e->menu.check = 1;
			}
		}
		mouse_menu_2(e, y, ev);
	}
	if (save != e->menu.i_img)
		Mix_PlayChannel(-1, e->sound.sound1, 0);
}

void				ft_menu(t_env *e)
{
	SDL_Event		ev;
	int				x;
	int				y;
	int				x2;
	int				y2;

	SDL_SetRelativeMouseMode(SDL_FALSE);
	SDL_ShowCursor(SDL_ENABLE);
	if (Mix_PlayingMusic() == 0)
		Mix_PlayMusic(e->sound.music, -1);
	while (e->menu.check != 1)
	{
		ft_menu_3(e, ev, &x, &y);
		while (SDL_PollEvent(&ev))
		{
			if (x2 != x || y2 != y)
				mouse_menu(e, x, y, ev);
			x2 = x;
			y2 = y;
			ft_menu_2(e, ev);
		}
	}
	if (!(SDL_SetRelativeMouseMode(SDL_TRUE) == 0))
		exit_error(17, ERR_7);
	SDL_ShowCursor(SDL_ENABLE);
}
