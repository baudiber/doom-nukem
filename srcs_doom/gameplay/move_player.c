/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:50:24 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/12 22:47:11 by gagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"


void	fly_mode(t_env * e)
{
	if ((e->state[SDL_SCANCODE_LCTRL] || e->state[SDL_SCANCODE_C]))
	{
		if (e->player.height > 10)
			e->player.height -= 30;
	}
	else if (e->state[SDL_SCANCODE_SPACE] && e->player.height <= (MAX_FLOORS * 2) * TILE_SIZE)
		e->player.height += 30;
}

void	crouch_and_jump(t_env *e)
{
	if ((e->state[SDL_SCANCODE_LCTRL] || e->state[SDL_SCANCODE_C]) && !(e->player_state & IS_FLY))
		e->player.height -= 64;
	if (e->state[SDL_SCANCODE_SPACE] && !(e->player_state & IS_FLY))
		e->player_state |= IS_JUMPING;
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
