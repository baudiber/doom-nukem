/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_switch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:12:42 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/12 05:17:17 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			weapon_switch(t_env *e)
{
	const Uint8		*state;

	// WARNING bad switch
	state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_1] && e->ui.weapon_firing == 0)
	{
		e->inv_info.index = (e->ui.weapon > 0) ? 1 : 0;
		e->ui.weapon = (e->inv_info.index > 0) ? 1 : 0;
	}
	if (state[SDL_SCANCODE_2] && e->inv_info.index == 1 \
		&& e->ui.weapon_firing == 0 && e->ui.weapon > 0)
	{
		e->inv_info.index = 2;
		e->ui.weapon = 2;
	}
}
