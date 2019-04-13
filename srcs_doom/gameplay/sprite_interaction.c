/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_interaction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <baudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 19:18:11 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/14 00:13:45 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		gun_animations_2(t_env *e)
{
	if (e->shotgun_info.index == 5 || e->pistol_info.index == 5)
	{
		e->ui.weapon_firing = 2;
		e->event.button.button = 0;
	}
	if (e->ui.weapon_firing == 2 && e->shotgun_info.index == 3 \
		&& e->pistol_info.index == 3)
	{
		e->ui.weapon_firing = 0;
		e->shotgun_info.index = 0;
		e->pistol_info.index = 0;
	}
	if (e->shotgun_info.index > 5 || e->pistol_info.index > 5)
	{
		e->face_info.index = 0;
		e->shotgun_info.index = 0;
		e->pistol_info.index = 0;
	}
}

static void		gun_animations(t_env *e)
{
	static float weapon_time;

	if (e->ui.weapon_firing)
	{
		weapon_time += e->time.frame_time;
		if (weapon_time > 0.09 && e->ui.weapon_firing)
		{
			if (e->ui.weapon_firing != 2)
			{
				e->shotgun_info.index++;
				e->pistol_info.index++;
			}
			if (e->ui.weapon_firing == 2)
			{
				e->shotgun_info.index--;
				e->pistol_info.index--;
			}
			gun_animations_2(e);
			weapon_time = 0;
		}
	}
}

void			animations(t_env *e)
{
	static float barrel_time;
	static float face_time;

	barrel_time += e->time.frame_time;
	if (barrel_time > 0.5)
	{
		e->barrel_tick = e->barrel_tick == false;
		barrel_time = 0;
	}
	face_time += e->time.frame_time;
	if (face_time > 1.25)
	{
		e->face_info.index = e->face_info.index \
			< 2 ? e->face_info.index + 1 : 0;
		face_time = 0;
	}
	gun_animations(e);
}
