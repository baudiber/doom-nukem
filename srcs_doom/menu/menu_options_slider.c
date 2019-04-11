/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_options_slider.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:29:16 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/11 21:44:52 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		ft_slider_2(t_env *e, int x)
{
	if (x >= 364 && x <= 420)
	{
		if (e->menu.i_img >= 4 && e->menu.i_img <= 8)
			e->menu.i_img = 6;
		Mix_VolumeMusic(128 * 0.025);
		Mix_Volume(-1, 128 * 0.025);
	}
	if (x >= 421 && x <= 477)
	{
		if (e->menu.i_img >= 4 && e->menu.i_img <= 8)
			e->menu.i_img = 7;
		Mix_VolumeMusic(128 * 0.05);
		Mix_Volume(-1, 128 * 0.05);
	}
	if (x >= 478 && x <= 533)
	{
		if (e->menu.i_img >= 4 && e->menu.i_img <= 8)
			e->menu.i_img = 8;
		Mix_VolumeMusic(128 * 0.10);
		Mix_Volume(-1, 128 * 0.10);
	}
}

void		ft_slider(t_env *e, int x, int y, SDL_Event ev)
{
	if (y >= 440 && y <= 485 && ev.button.button == SDL_BUTTON_LEFT)
	{
		if (x >= 250 && x <= 306)
		{
			if (e->menu.i_img >= 4 && e->menu.i_img <= 8)
				e->menu.i_img = 4;
			Mix_VolumeMusic(128 * 0);
			Mix_Volume(-1, 128 * 0);
		}
		if (x >= 307 && x <= 363)
		{
			if (e->menu.i_img >= 4 && e->menu.i_img <= 8)
				e->menu.i_img = 5;
			Mix_VolumeMusic(128 * 0.01);
			Mix_Volume(-1, 128 * 0.01);
		}
		ft_slider_2(e, x);
	}
}
