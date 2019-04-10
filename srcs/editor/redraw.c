/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:13:59 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 15:31:29 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

unsigned int		*apply_texture(t_env *e)
{
	unsigned int	*texture;
	int				type;

	if (e->type == 0)
		type = 0;
	else if (e->type == 1)
		type = NWALL; 	//	type = le nombre de toute les textures avant ce type la si type == 2 \
					//	alors compter toutes les texture de type 0 et type 1 et les additionner
	else if (e->type == 2)
		type = NWALL + NFLOOR;
	else if (e->type == 3)
		type = NWALL + NFLOOR + NSPRITE;
	else if (e->type == 4)
		type = 0;
	if (e->texture.texture >= 1 && e->texture.texture <= (NTEX - type))
		texture = e->texture.tex[e->texture.texture + 4 + type];
	else
	{
		ft_putendl("YOPOOOO");
		texture = NULL;
		ft_putendl("YOPOOOO");
	}
	return (texture);
}

void				redraw_block(t_env *e, int posx, int posy)
{
	int x;
	int y;
	unsigned int *texture;

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

void				redraw(t_env *e)
{
	int x;
	int y;

	SDL_FillRect(e->window.screen, &e->grid.grid_rect, 0xE0E0E0);
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
	{
		if (e->window.event.key.keysym.sym != SDLK_KP_PLUS
		&& e->window.event.key.keysym.sym != SDLK_KP_MINUS
		&& e->window.event.key.keysym.sym != SDLK_KP_DIVIDE
		&& e->window.event.key.keysym.sym != SDLK_KP_MULTIPLY)
		{
			draw_panel_tier(e);
			draw_panel_grid_size(e);
		}
	}
}
