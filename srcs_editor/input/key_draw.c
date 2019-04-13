/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:49:15 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/13 22:19:07 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	select_grid_block(t_env *e)
{
	e->grid.mouseposgridx = ((e->grid.mouseposx - \
		MARGIN - PANEL) / e->grid.padx);
	e->grid.mouseposgridy = ((e->grid.mouseposy - MARGIN) / e->grid.pady);
	if (e->texture.texture && e->window.event.button.button == SDL_BUTTON_LEFT)
	{
		if ((e->type == 2 && e->sprite_nb > 1) || e->texture.texture == 1)
			draw_texture_grid(e);
		else if (e->type != 2)
			draw_texture_grid(e);
	}
	else if (e->window.event.button.button == SDL_BUTTON_RIGHT)
		erase_texture_grid(e);
}
