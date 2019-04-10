/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:37:38 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 15:23:30 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	mouse_click(t_env *e)
{
	SDL_GetMouseState(&e->grid.mouseposx, &e->grid.mouseposy);
	if (e->grid.mouseposx >= (MARGIN + PANEL) && e->grid.mouseposx \
		<= (WIN_W - MARGIN) && e->grid.mouseposy \
		>= MARGIN && e->grid.mouseposy <= (WIN_H - MARGIN))
		select_grid_block(e);
}

void	key_input(t_env *e)
{
	change_tier(e);
	change_grid_size(e);
	change_panel(e);
	mouse_click(e);
}
