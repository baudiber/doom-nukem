/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:59:52 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/13 23:59:58 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

static void				welcome(t_env *e)
{
	e->draw[0].text = TTF_RenderText_Solid(e->draw[0].font,\
			"Press     Enter", e->draw[0].white);
	e->draw[0].position.x = WIN_W / 2 - 390;
	e->draw[0].position.y = WIN_H / 2 - 100;
	SDL_BlitSurface(e->draw[0].text, NULL, e->window.screen,\
		&e->draw[0].position);
	SDL_FreeSurface(e->draw[0].text);
	if (e->window.event.type == SDL_KEYDOWN)
		if (e->window.event.key.keysym.sym == SDLK_RETURN)
		{
			e->f[e->panel_index](e);
			e->wellcome_screen = 0;
		}
}

void					main_loop(t_env *e)
{
	while (true)
	{
		while (SDL_PollEvent(&e->window.event))
		{
			if (e->window.event.type == SDL_QUIT \
				|| (e->window.event.type == SDL_KEYDOWN \
					&& e->window.event.key.keysym.sym == SDLK_ESCAPE))
				exit(0);
			if (e->wellcome_screen == 1)
				welcome(e);
			else
			{
				key_input(e);
				draw_grid(e);
				if (e->wellcome_screen == 0)
				{
					e->wellcome_screen = 2;
					draw_panel_text(e);
					redraw(e);
					draw_grid(e);
				}
			}
			SDL_UpdateWindowSurface(e->window.win);
		}
	}
}
