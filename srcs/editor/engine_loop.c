/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:59:52 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 15:22:34 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		wellcome(t_env *e)
{
	e->draw[0].text = TTF_RenderText_Solid(e->draw[0].font, "Press     Enter", e->draw[0].white);
	e->draw[0].position.x = WIN_W / 2 - 390;
	e->draw[0].position.y = WIN_H / 2 - 100;
	SDL_BlitSurface(e->draw[0].text, NULL, e->window.screen, &e->draw[0].position); /* Blit du texte */
	if (e->window.event.type == SDL_KEYDOWN)
		if (e->window.event.key.keysym.sym == SDLK_RETURN)
		{
			SDL_FillRect(e->window.screen, NULL, 0xE0E0E0);
			e->f[e->panel_index](e);
			e->wellcome_screen = 0;
		}
}

void		engine_loop(t_env *e)
{
	while (1)
	{
		while (SDL_PollEvent(&e->window.event))
		{
			if (e->window.event.type == SDL_KEYDOWN)
				if (e->window.event.key.keysym.sym == SDLK_ESCAPE)
					exit(0);
			if (e->wellcome_screen == 1)
				wellcome(e);
			else
			{
				key_input(e);
				ft_putnbr(e->type);
				ft_putchar('\n');
				editor(e);
				if (e->wellcome_screen == 0)
				{
					draw_panel_grid_size(e);
					draw_panel_tier(e);
					e->wellcome_screen = 2;
				}
			}
			SDL_UpdateWindowSurface(e->window.win);
		}
	}
}
