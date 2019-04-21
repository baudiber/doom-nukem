/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_gridsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:43:56 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/11 19:23:19 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

static void			check_assign(t_env *e)
{
	if (e->window.event.key.keysym.sym == SDLK_KP_PLUS \
		&& e->grid.x < MAX_SIZE)
	{
		e->grid.x++;
		e->dif_size = 1;
	}
	if (e->window.event.key.keysym.sym == SDLK_KP_MINUS && e->grid.x > 1)
	{
		e->grid.x--;
		e->dif_size = 0;
	}
	if (e->window.event.key.keysym.sym == SDLK_KP_DIVIDE && e->grid.y > 1)
	{
		e->grid.y--;
		e->dif_size = 0;
	}
	if (e->window.event.key.keysym.sym == SDLK_KP_MULTIPLY \
		&& e->grid.y < MAX_SIZE)
	{
		e->grid.y++;
		e->dif_size = 1;
	}
}

void				change_grid_size(t_env *e)
{
	if (e->window.event.type == SDL_KEYDOWN \
		&& (e->window.event.key.keysym.sym == SDLK_KP_PLUS \
		|| e->window.event.key.keysym.sym == SDLK_KP_MINUS \
		|| e->window.event.key.keysym.sym == SDLK_KP_DIVIDE \
		|| e->window.event.key.keysym.sym == SDLK_KP_MULTIPLY))
	{
		check_assign(e);
		refresh_grid_var(e);
		redraw(e);
	}
}
