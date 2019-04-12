/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:49:15 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/12 19:23:25 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	select_grid_block(t_env *e)
{
	e->grid.mouseposgridx = ((e->grid.mouseposx - \
		MARGIN - PANEL) / e->grid.padx);
	e->grid.mouseposgridy = ((e->grid.mouseposy - MARGIN) / e->grid.pady);
	if (e->texture.texture && e->window.event.button.button == SDL_BUTTON_LEFT)
		draw_texture_grid(e);
	else if (e->window.event.button.button == SDL_BUTTON_RIGHT)
		erase_texture_grid(e);
}
