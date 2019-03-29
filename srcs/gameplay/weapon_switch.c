/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_switch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:12:42 by roddavid          #+#    #+#             */
/*   Updated: 2019/03/26 11:04:01 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			weapon_switch(t_env *e)
{
	const Uint8		*state;

	state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_1] && e->ui.weapon_firing == 0)
		e->ui.weapon = 0;
	if (state[SDL_SCANCODE_2] && e->inv_info.index == 1 && e->ui.weapon_firing == 0)
		e->ui.weapon = 1;
}
