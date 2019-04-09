/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:16:55 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/09 16:45:39 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	draw_texture_grid(t_e *e)
{
	int x;
	int y;
	unsigned int *texture;

	texture = apply_texture(e);
	e->texture.y = 0;
	y = e->grid.mouseposgridy * e->grid.pady + MARGIN;
	while (++y < ((e->grid.mouseposgridy + 1) * e->grid.pady + MARGIN) \
	&& e->grid.mouseposgridy < e->grid.y)
	{
		e->texture.x = 0;
		x = e->grid.mouseposgridx * e->grid.padx + MARGIN + PANEL;
		while (++x < ((e->grid.mouseposgridx + 1) * e->grid.padx + MARGIN \
		+ PANEL) && e->grid.mouseposgridx < e->grid.x)
		{
			e->buff[WIN_W * y + x] = texture[((int)e->texture.y * TEX_SIZE) \
				+ (int)e->texture.x];
			e->texture.x += e->texture.ratiox;
		}
		e->texture.y += e->texture.ratioy;
	}
	if (e->grid.mouseposgridy < e->grid.y && e->grid.mouseposgridx < e->grid.x)
		e->tab[e->type][e->tier][e->grid.mouseposgridy][e->grid.mouseposgridx] \
		= e->texture.texture;
}
