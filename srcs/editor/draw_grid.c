/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:22:14 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 15:22:13 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		refresh_grid_var(t_env *e)
{
	e->grid.padx = (WIN_W - (MARGIN * 2) - PANEL) / (float)e->grid.x;
	e->grid.pady = (WIN_H - (MARGIN * 2)) / (float)e->grid.y;
	e->texture.ratiox = TEX_SIZE / e->grid.padx;
	e->texture.ratioy = TEX_SIZE / e->grid.pady;
	e->grid.countpadx = 1;
	e->grid.countpady = 1;
}

void		draw_line_in_grid(t_env *e)
{
	int	x;
	int	y;

	y = MARGIN - 1;
	while (++y < (WIN_H - MARGIN))
	{
		x = MARGIN + PANEL - 1;
		e->grid.countpadx = 1;
		while (++x < (WIN_W - MARGIN))
		{
			if (x == (int)(e->grid.countpadx * e->grid.padx + MARGIN + PANEL))
			{
				e->buff[WIN_W * y + x] = 0x0;
				e->grid.countpadx++;
			}
			if (y == (int)(e->grid.countpady * e->grid.pady + MARGIN))
			{
				e->buff[WIN_W * y + x] = 0x0;
				if (x == WIN_W - MARGIN - 1)
					e->grid.countpady++;
			}
		}
	}
}

void		draw_outline_grid(t_env *e)
{
	int x;
	int y;

	y = MARGIN - 1;
	while (++y < (WIN_H - MARGIN))
	{
		x = MARGIN + PANEL - 1;
		while (++x < (WIN_W - MARGIN))
		{
			if (x == MARGIN + PANEL || x == WIN_W - (MARGIN + 1))
			e->buff[WIN_W * y + x] = 0x0;
			if (y == MARGIN || y == WIN_H - (MARGIN + 1))
			e->buff[WIN_W * y + x] = 0x0;
		}
	}
}

void		draw_grid(t_env *e)
{
	//SI VAR BOUGE PAS, NE PAS REFRESH
	refresh_grid_var(e);
	draw_outline_grid(e);
	draw_line_in_grid(e);
}
