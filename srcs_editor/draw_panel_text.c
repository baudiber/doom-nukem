/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_panel_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:59:58 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 22:29:39 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		draw_panel_tier(t_env *e)
{
	char		*str;

	str = (e->tier == 0) ? ft_strdup("RDC") : ft_itoa(e->tier);
	e->draw[1].position.x = 190;
	e->draw[1].position.y = 186;
	e->draw[1].text = TTF_RenderText_Solid(e->draw[1].font, str, e->draw[1].white);
	e->f[e->panel_index](e);
	SDL_BlitSurface(e->draw[1].text, NULL, e->window.screen, &e->draw[1].position);
	SDL_FreeSurface(e->draw[1].text);
	(str) ? ft_strdel(&str) : 0;
}

void			draw_panel_grid_y(t_env *e)
{
	char			*str;

	str = ft_itoa(e->grid.y);
	e->draw[2].position.x = 110;
	e->draw[2].position.y = 130;
	e->draw[2].text = TTF_RenderText_Solid(e->draw[2].font, str, e->draw[2].white);
	SDL_BlitSurface(e->draw[2].text, NULL, e->window.screen, &e->draw[2].position);
	SDL_FreeSurface(e->draw[2].text);
	(str) ? ft_strdel(&str) : 0;
}

void			draw_panel_grid_x(t_env *e)
{
	char			*str;

	str = ft_itoa(e->grid.x);
	e->draw[3].position.x = 300;
	e->draw[3].position.y = 130;
	e->draw[3].text = TTF_RenderText_Solid(e->draw[3].font, str, e->draw[3].white);
	SDL_BlitSurface(e->draw[3].text, NULL, e->window.screen, &e->draw[3].position);
	SDL_FreeSurface(e->draw[3].text);
	(str) ? ft_strdel(&str) : 0;
}

void		draw_panel_text(t_env *e)
{
	draw_panel_tier(e);
	draw_panel_grid_y(e);
	draw_panel_grid_x(e);
}
