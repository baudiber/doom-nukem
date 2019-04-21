/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:13:59 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/12 19:22:41 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

static void					fill_rect(t_env *e)
{
	int						i;
	int						j;

	i = 0;
	while (i < WIN_H)
	{
		j = PANEL;
		while (j < WIN_W)
		{
			e->buff[WIN_W * i + j] = 0xE0E0E0;
			j++;
		}
		i++;
	}
}

static int					get_number_of_texture(t_env *e)
{
	if (e->type == 0)
		return (NWALL);
	else if (e->type == 1)
		return (NFLOOR);
	else if (e->type == 2)
		return (NSPRITE);
	else if (e->type == 3)
		return (NLIGHT);
	else if (e->type == 4)
		return (NEVENT);
	else
		return (0);
}

unsigned int				*apply_texture(t_env *e)
{
	int						type;
	unsigned int			*texture;

	if (e->type == 0)
		type = 0;
	else if (e->type == 1)
		type = NWALL;
	else if (e->type == 2)
		type = NWALL + NFLOOR;
	else if (e->type == 3)
		type = NWALL + NFLOOR + NSPRITE;
	else if (e->type == 4)
		type = NWALL + NFLOOR + NSPRITE + NLIGHT;
	if (e->texture.texture >= 1 \
			&& e->texture.texture <= (get_number_of_texture(e)))
		texture = e->texture.tex[e->texture.texture + 4 + type];
	else
		texture = NULL;
	return (texture);
}

static void					redraw_block(t_env *e, int posx, int posy)
{
	int						x;
	int						y;
	unsigned int			*texture;

	e->texture.y = 0;
	texture = apply_texture(e);
	if (!texture)
		return ;
	y = posy * e->grid.pady + MARGIN;
	while (++y < ((posy + 1) * e->grid.pady + MARGIN))
	{
		x = posx * e->grid.padx + MARGIN + PANEL;
		e->texture.x = 0;
		while (++x < ((posx + 1) * e->grid.padx + MARGIN + PANEL))
		{
			e->buff[WIN_W * y + x] = texture[((int)e->texture.y * TEX_SIZE) \
				+ (int)e->texture.x];
			e->texture.x += e->texture.ratiox;
		}
		e->texture.y += e->texture.ratioy;
	}
}

void						redraw(t_env *e)
{
	int x;
	int y;

	fill_rect(e);
	y = -1;
	while (++y < e->grid.y)
	{
		x = -1;
		while (++x < e->grid.x)
		{
			if (e->tab[e->type][e->tier][y][x] != 0)
			{
				e->texture.texture = e->tab[e->type][e->tier][y][x];
				redraw_block(e, x, y);
			}
		}
	}
	if (e->window.event.type == SDL_KEYDOWN)
		draw_panel_text(e);
}
