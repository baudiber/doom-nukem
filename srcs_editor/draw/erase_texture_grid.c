/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_texture_grid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:27:52 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/11 19:28:23 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	erase_texture_grid(t_env *e)
{
	int x;
	int y;
	int val1;
	int val2;

	val1 = ((e->grid.mouseposgridy + 1) * e->grid.pady + MARGIN);
	val2 = ((e->grid.mouseposgridx + 1) * e->grid.padx + MARGIN + PANEL);
	y = e->grid.mouseposgridy * e->grid.pady + MARGIN;
	while (++y < val1)
	{
		x = e->grid.mouseposgridx * e->grid.padx + MARGIN + PANEL;
		while (++x < val2)
		{
			e->buff[WIN_W * y + x] = 0xE0E0E0;
		}
	}
	e->tab[e->type][e->tier][e->grid.mouseposgridy][e->grid.mouseposgridx] = 0;
}
