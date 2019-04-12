/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <baudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:07:59 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/12 06:38:42 by baudiber         ###   ########.fr       */
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
}

void	restart(t_env *e)
{
	int		i;

	i = -1;
	re_init_map(&e->data);
	init_player(e);
	e->horizon = 0;
	e->draw.skybox_y = e->horizon - e->files.skybox->h;
	e->ui.weapon = 0;
	e->ui.trumpet = 0;
	e->inv_info.index = 0;
	while (++i < e->sprite_nb)
	{
		if (e->sprites[i].tex > 7 && e->sprites[i].tex < 13)
			e->sprites[i].tex = 0;
		e->sprites[i].dead = 0;
		e->sprites[i].visible = true;
	}
}

void	end_game(t_env *e, char *msg)
{
	int		i;
	t_point	pt;

	pt.x = WIN_W * 0.5 - 120;
	pt.y = e->render_limit * 0.5;
	i = 1;
	i = -1;
	while (++i < (WIN_W * WIN_W))
		e->buff[i] = (e->buff[i] >> 1) & 8355711;
	draw_text(e, pt, END_GAME, msg);
	SDL_UpdateWindowSurface(e->win);
	sleep(3);
	e->menu.check = 0;
}
