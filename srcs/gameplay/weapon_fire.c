/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_fire.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:24:44 by roddavid          #+#    #+#             */
/*   Updated: 2019/03/28 21:54:16 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
