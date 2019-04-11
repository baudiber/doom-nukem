/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:07:59 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/11 21:52:13 by baudiber         ###   ########.fr       */
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
			e->player.hp -= 20;
			lava_tick = 0;
		}
	}
	else
		lava_tick = 0;
	if (e->player.hp <= 0)
		wasted(e);
}

void	wasted(t_env *e)
{
	//e->player.state  = dead
	/*
	int		i;

	i = -1;
	while (++i < (WIN_W * WIN_W))
	{
		e->buff[i] = (e->buff[i] >> 1) & 8355711;
	}
	*/
	e->menu.check = 0;
	ft_menu(e);	
}
