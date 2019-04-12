/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <baudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:07:59 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/12 03:42:59 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	floor_is_lava(t_env *e)
{
	static float	lava_tick;

	if (e->data.map[DEVENT][e->player.floor][e->player.map.y]\
		[e->player.map.x] == 1)
	{
		lava_tick += e->time.frame_time;
		if (lava_tick > 1.0)
		{
			e->player.hp -= 50;
			lava_tick = 0;
		}
	}
	else
		lava_tick = 0;
	if (e->player.hp <= 0)
		end_game(e, "WASTED");
}

void	end_game(t_env *e, char *msg)
{
	int		i;
	t_point	pt;

	pt.x = WIN_W * 0.5 - 120;
	pt.y = e->render_limit * 0.5;
	draw_text(e, pt, END_GAME, msg);
	i = -1;
	while (++i < (WIN_W * WIN_W))
		e->buff[i] = (e->buff[i] >> 1) & 8355711;
	SDL_UpdateWindowSurface(e->win);
	sleep(4);
	e->menu.check = 0;
	ft_menu(e);
}
