/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:44:09 by roddavid          #+#    #+#             */
/*   Updated: 2019/03/25 15:15:56 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_struct_minimap(t_env *e)
{
	e->minimap.i = -1;
	e->minimap.i2 = 0;
	e->minimap.j = -1;
	e->minimap.j2 = 0;
	e->minimap.x = -1;
	e->minimap.y = -1;
	e->minimap.pady = 0;
	e->minimap.padx = 0;
}

void		minimap(t_env *e)
{
	const Uint8 *state;

	state = SDL_GetKeyboardState(NULL);
	init_struct_minimap(e);
	if (state[SDL_SCANCODE_L])
	{
		draw_map_big(e);
		draw_player_big(e);
	}
	else
	{
		draw_map_small(e);
		draw_player_small(e);
	}
}
