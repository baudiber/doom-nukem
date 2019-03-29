/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_aim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:45:35 by roddavid          #+#    #+#             */
/*   Updated: 2019/03/26 12:01:41 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	mouse_aim_x(t_env *e)
{
	if (e->prev_mouse.x > e->event.motion.x)
	{
		e->player.angle -= e->angle.a_2;
		e->draw.skybox_x += 65;
	}
	else if (e->prev_mouse.x < e->event.motion.x)
	{
		e->player.angle += e->angle.a_2;
		e->draw.skybox_x -= 65;
	}
}

void	mouse_aim_y(t_env *e)
{
	if (e->prev_mouse.y > e->event.motion.y)
	{
		if (e->horizon < 1000)
		{
			e->horizon += 15;
			e->draw.skybox_y += 15;
		}
	}
	else if (e->prev_mouse.y < e->event.motion.y)
	{
		if (e->horizon > -750)
		{
			e->horizon -= 15;
			e->draw.skybox_y -= 15;
		}
	}
	if (e->event.motion.y == 0 || e->event.motion.x == 0 || \
		e->event.motion.y == WIN_H - 1 || e->event.motion.x == WIN_W - 1)
		SDL_WarpMouseInWindow(e->win, WIN_W / 2, WIN_H / 2);
}
