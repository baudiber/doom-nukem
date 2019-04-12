/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 03:02:12 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/12 19:02:07 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	draw_text(t_env *e, t_point pt, int type, char *msg)
{
	SDL_Rect	where;

	where.x = pt.x;
	where.y = pt.y;
	if (type == END_GAME)
	{
		e->draw.text_surface = TTF_RenderText_Solid(e->draw.font_end_game, msg, e->draw.red);
		SDL_BlitSurface(e->draw.text_surface, NULL, e->screen, &where);
		SDL_FreeSurface(e->draw.text_surface);
	}
	if (type == HEALTH)
	{
		e->draw.text_surface = TTF_RenderText_Solid(e->draw.font_hp, msg, e->draw.red);
		SDL_BlitSurface(e->draw.text_surface, NULL, e->screen, &where);
		SDL_FreeSurface(e->draw.text_surface);
	}
}
