/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:50:24 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/03 19:26:10 by gagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	crouch_and_jump(t_env *e)
{
//	float g = 9.81;
//	int tmp;
	
	if (e->state[SDL_SCANCODE_LCTRL] || e->state[SDL_SCANCODE_C])
		e->player.height -= 5;
	else if (e->state[SDL_SCANCODE_SPACE])
		//e->player.height += e->player.speed * e->time.delta_time + 140;
		e->player.height += 5;
}

void	walk_forward_and_backward(t_env *e, t_point *new_pos, int *tmpangle)
{
	if (e->state[SDL_SCANCODE_W])
		get_delta(e->player.angle, e, new_pos);
	else if (e->state[SDL_SCANCODE_S])
	{
		*tmpangle = e->player.angle + e->angle.a_180;
		if (*tmpangle > e->angle.a_360)
			*tmpangle -= e->angle.a_360;
		get_delta(*tmpangle, e, new_pos);
	}
}

void	strafe(t_env *e, t_point *new_pos, int *tmpangle)
{
	if (e->state[SDL_SCANCODE_A])
	{
		*tmpangle = e->player.angle - e->angle.a_90;
		if (*tmpangle < 0)
			*tmpangle += e->angle.a_360;
		get_delta(*tmpangle, e, new_pos);
	}
	else if (e->state[SDL_SCANCODE_D])
	{
		*tmpangle = e->player.angle + e->angle.a_90;
		if (*tmpangle > e->angle.a_360)
			*tmpangle -= e->angle.a_360;
		get_delta(*tmpangle, e, new_pos);
	}
}

void	strafe_backward(t_env *e, t_point *new_pos, int *tmpangle)
{
	if (e->state[SDL_SCANCODE_S] && e->state[SDL_SCANCODE_A])
	{
		*tmpangle = e->player.angle - e->angle.a_140;
		if (*tmpangle < 0)
			*tmpangle += e->angle.a_360;
		get_delta(*tmpangle, e, new_pos);
	}
	else if (e->state[SDL_SCANCODE_S] && e->state[SDL_SCANCODE_D])
	{
		*tmpangle = e->player.angle + e->angle.a_140;
		if (*tmpangle > e->angle.a_360)
			*tmpangle -= e->angle.a_360;
		get_delta(*tmpangle, e, new_pos);
	}
}

void	strafe_forward(t_env *e, t_point *new_pos, int *tmpangle)
{
	if (e->state[SDL_SCANCODE_A] && e->state[SDL_SCANCODE_W])
	{
		*tmpangle = e->player.angle - e->angle.a_40;
		if (*tmpangle < 0)
			*tmpangle += e->angle.a_360;
		get_delta(*tmpangle, e, new_pos);
	}
	else if (e->state[SDL_SCANCODE_D] && e->state[SDL_SCANCODE_W])
	{
		*tmpangle = e->player.angle + e->angle.a_40;
		if (*tmpangle > e->angle.a_360)
			*tmpangle -= e->angle.a_360;
		get_delta(*tmpangle, e, new_pos);
	}
}
