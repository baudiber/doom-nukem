/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:37:38 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/11 19:21:08 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

static void		mouse_click(t_env *e)
{
	SDL_GetMouseState(&e->grid.mouseposx, &e->grid.mouseposy);
	if (e->grid.mouseposx >= (MARGIN + PANEL) && e->grid.mouseposx \
		<= (WIN_W - MARGIN) && e->grid.mouseposy \
		>= MARGIN && e->grid.mouseposy <= (WIN_H - MARGIN))
		select_grid_block(e);
	if (e->grid.mouseposx >= 40 && e->grid.mouseposx <= 180 \
		&& e->grid.mouseposy >= 1160 && e->grid.mouseposy <= 1230 \
		&& e->window.event.button.button == SDL_BUTTON_LEFT)
	{
		ft_putendl("You saved succesfully");
		saving(e);
	}
	if (e->grid.mouseposx >= 260 && e->grid.mouseposx <= 400 \
		&& e->grid.mouseposy >= 1160 && e->grid.mouseposy <= 1230 \
		&& e->window.event.button.button == SDL_BUTTON_LEFT)
	{
		ft_putendl("Goodbye");
		exit(0);
	}
}

void			key_input(t_env *e)
{
	change_tier(e);
	change_grid_size(e);
	change_panel(e);
	mouse_click(e);
}
