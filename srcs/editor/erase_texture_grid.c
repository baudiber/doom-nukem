/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_texture_grid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:27:52 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 15:22:37 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	erase_texture_grid(t_env *e)
{
	int x;
	int y;

	y = e->grid.mouseposgridy * e->grid.pady + MARGIN;
	while (++y < ((e->grid.mouseposgridy + 1) * e->grid.pady + MARGIN))
	{
		x = e->grid.mouseposgridx * e->grid.padx + MARGIN + PANEL;
		while (++x < ((e->grid.mouseposgridx + 1) * e->grid.padx + MARGIN + PANEL))
		{
			e->buff[WIN_W * y + x] = 0xE0E0E0;
		}
	}
	e->tab[e->type][e->tier][e->grid.mouseposgridy][e->grid.mouseposgridx] = 0;
}
