/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_panel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:45:43 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 15:23:30 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	choose_texture(t_env *e)
{
	//if (e->window.event.button.state == SDL_PRESSED) <=== FOR MOUSE CLICK
	if (e->window.event.type == SDL_KEYDOWN)
	{
		if (e->window.event.key.keysym.sym == SDLK_r)
			e->texture.texture = 1;
		if (e->window.event.key.keysym.sym == SDLK_b)
			e->texture.texture = 2;
		if (e->window.event.key.keysym.sym == SDLK_g)
			e->texture.texture = 3;
	}
}

void	change_panel(t_env *e)
{
	if (e->window.event.type == SDL_KEYDOWN)
	{
		if (e->window.event.key.keysym.sym == SDLK_TAB)
		{
			if (e->panel_index < 4)
				e->panel_index++;
			else
				e->panel_index = 0;
			e->f[e->panel_index](e);
		}
		if (e->window.event.key.keysym.sym == SDLK_s)
			saving(e);
		redraw(e);
	}
	choose_texture(e);
}

void	change_tier(t_env *e)
{
	if (e->window.event.type == SDL_KEYDOWN)
	{
		if (e->window.event.key.keysym.sym == SDLK_UP && e->tier < TIER)
		{
			e->tier++;
			if (e->tier == TIER)
				e->tier = 0;

		}
		if (e->window.event.key.keysym.sym == SDLK_DOWN && e->tier >= 0)
		{
			e->tier--;
			if (e->tier == -1)
				e->tier = TIER - 1;
		}
		redraw(e);
	}
}
