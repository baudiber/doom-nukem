/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_panel_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:59:58 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 15:22:23 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	draw_panel_tier(t_env *e)
{
	char *str;

	str = ft_itoa(e->tier);
	if (e->tier == 0)
		str = "RDC";
	e->draw[1].font = TTF_OpenFont("font/BEBAS.TTF", 40);
	e->draw[1].position.x = 308;
	e->draw[1].position.y = 245;
	if (e->tier == 0)
	{
		str = "RDC";
		e->draw[1].position.x = 295;
		e->draw[1].position.y = 249;
		e->draw[1].font = TTF_OpenFont("font/BEBAS.TTF", 28);
	}
	e->draw[1].text = TTF_RenderText_Solid(e->draw[1].font, str, e->draw[1].white);
	e->f[e->panel_index](e);
	SDL_BlitSurface(e->draw[1].text, NULL, e->window.screen, &e->draw[1].position);
	SDL_BlitSurface(e->draw[2].text, NULL, e->window.screen, &e->draw[2].position);
	SDL_BlitSurface(e->draw[3].text, NULL, e->window.screen, &e->draw[3].position);
}

void	draw_panel_grid_size(t_env *e)
{
	char *str;

	str = ft_itoa(e->grid.y);
	e->draw[2].font = TTF_OpenFont("font/BEBAS.TTF", 40);
	e->draw[2].position.x = 10;
	e->draw[2].position.y = 10;
	e->draw[2].text = TTF_RenderText_Solid(e->draw[2].font, str, e->draw[2].white);
	str = ft_itoa(e->grid.x);
	e->draw[3].font = TTF_OpenFont("font/BEBAS.TTF", 40);
	e->draw[3].position.x = PANEL - 50;
	e->draw[3].position.y = 10;
	e->draw[3].text = TTF_RenderText_Solid(e->draw[3].font, str, e->draw[3].white);
}
