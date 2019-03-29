/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_options_slider.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:29:16 by roddavid          #+#    #+#             */
/*   Updated: 2019/03/29 17:45:08 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		ft_slider_2(t_env *e, int x)
{
	if (x >= 581 && x <= 645)
	{
		if (e->menu.i_img >= 4 && e->menu.i_img <= 8)
			e->menu.i_img = 6;
		Mix_VolumeMusic(128 * 0.025);
		Mix_Volume(-1, 128 * 0.025);
	}
	if (x >= 646 && x <= 730)
	{
		if (e->menu.i_img >= 4 && e->menu.i_img <= 8)
			e->menu.i_img = 7;
		Mix_VolumeMusic(128 * 0.05);
		Mix_Volume(-1, 128 * 0.05);
	}
	if (x >= 731 && x <= 830)
	{
		if (e->menu.i_img >= 4 && e->menu.i_img <= 8)
			e->menu.i_img = 8;
		Mix_VolumeMusic(128 * 0.10);
		Mix_Volume(-1, 128 * 0.10);
	}
}

void		ft_slider(t_env *e, int x, int y, SDL_Event ev)
{
	if (y >= 600 && y <= 650 && ev.button.button == SDL_BUTTON_LEFT)
	{
		if (x >= 400 && x <= 480)
		{
			if (e->menu.i_img >= 4 && e->menu.i_img <= 8)
				e->menu.i_img = 4;
			Mix_VolumeMusic(128 * 0);
			Mix_Volume(-1, 128 * 0);
		}
		if (x >= 481 && x <= 580)
		{
			if (e->menu.i_img >= 4 && e->menu.i_img <= 8)
				e->menu.i_img = 5;
			Mix_VolumeMusic(128 * 0.01);
			Mix_Volume(-1, 128 * 0.01);
		}
		ft_slider_2(e, x);
	}
}
