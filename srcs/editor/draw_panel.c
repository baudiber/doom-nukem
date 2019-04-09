/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:58:47 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/09 16:45:39 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	draw_panel_wall(t_e *e)
{
	SDL_BlitSurface(e->texture.image[0], NULL, e->window.screen, NULL);
	e->type = 0;
}

void	draw_panel_floor(t_e *e)
{
	SDL_BlitSurface(e->texture.image[1], NULL, e->window.screen, NULL);
	e->type = 1;
}

void	draw_panel_sprite(t_e *e)
{
	SDL_BlitSurface(e->texture.image[2], NULL, e->window.screen, NULL);
	e->type = 2;
}

void	draw_panel_light(t_e *e)
{
	SDL_BlitSurface(e->texture.image[3], NULL, e->window.screen, NULL);
	e->type = 3;
}

void	draw_panel_event(t_e *e)
{
	SDL_BlitSurface(e->texture.image[4], NULL, e->window.screen, NULL);
	e->type = 4;
}
