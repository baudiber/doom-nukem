/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_fire.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:24:44 by roddavid          #+#    #+#             */
/*   Updated: 2019/03/29 17:45:08 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		weapon_fire(t_env *e)
{
	if (e->event.button.button == SDL_BUTTON_LEFT)
	{
		if (!e->ui.weapon_firing)
		{
			e->ui.weapon_fired = 1;
			e->ui.weapon_firing = 1;
			e->face_info.index = 4;
			if (e->ui.weapon)
				Mix_PlayChannel(-1, e->sound.sound6, 0);
			else
				Mix_PlayChannel(-1, e->sound.sound5, 0);
		}
	}
}
