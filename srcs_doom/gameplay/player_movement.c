/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <baudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 19:09:47 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/13 02:43:27 by gagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			get_delta(int angle, t_env *e, t_point *new_pos)
{
	new_pos->x += e->cos_table[angle] * (e->player.speed * e->time.delta_time);
	new_pos->y += e->sin_table[angle] * (e->player.speed * e->time.delta_time);
}

void			get_jump_pos(t_env *e, double *fall_time)
{
	float g;

	g = 9.81;
	if ((e->player_state & IS_FALLING) && !(e->player_state & IS_FLY))
	{
		*fall_time += e->time.frame_time;
		e->player.height += -0.5 * g * pow(*fall_time, 2) + \
			*fall_time * (e->max_speed * 8) * e->sin_table[e->angle.a_270];
	}
}

static void		move_player_2(t_env *e, int *tmpangle, t_point *new_pos)
{
	if ((e->state[SDL_SCANCODE_A] || e->state[SDL_SCANCODE_D]) \
	&& e->state[SDL_SCANCODE_W])
		strafe_forward(e, new_pos, tmpangle);
	else if (e->state[SDL_SCANCODE_S] && (e->state[SDL_SCANCODE_A] \
		|| e->state[SDL_SCANCODE_D]))
		strafe_backward(e, new_pos, tmpangle);
	else if (e->state[SDL_SCANCODE_A] || e->state[SDL_SCANCODE_D])
		strafe(e, new_pos, tmpangle);
	else if (e->state[SDL_SCANCODE_W] || e->state[SDL_SCANCODE_S])
		walk_forward_and_backward(e, new_pos, tmpangle);
	if (!(e->player_state & IS_FLY))
		collision(e, new_pos);
	else
		e->player.pos = *new_pos;
}

void			move_player(t_env *e)
{
	int				tmpangle;
	t_point			new_pos;
	static double	fall_time;

	if (!ray_is_in_the_map(e->player.map, e))
		restart(e);
	new_pos = e->player.pos;
	check_state(e);
	fly_or_fall(e);
	jump_anim(e);
	if (!(e->player_state & IS_JUMPING) && (e->player.height) \
		> e->player.dist_to_floor && !(e->state[SDL_SCANCODE_LCTRL]))
		get_jump_pos(e, &fall_time);
	else
		fall_time = 0;
	if (e->state[SDL_SCANCODE_A] || e->state[SDL_SCANCODE_W] \
			|| e->state[SDL_SCANCODE_S] || e->state[SDL_SCANCODE_D])
		e->player.moving = true;
	else
	{
		e->player.moving = false;
		return ;
	}
	move_player_2(e, &tmpangle, &new_pos);
}

void			mouse_aim(t_env *e)
{
	int			x;
	int			y;

	SDL_GetRelativeMouseState(&x, &y);
	e->player.angle += x * 2;
	e->draw.skybox_x -= x * 2;
	if (y > 0)
	{
		if (e->horizon > -750)
		{
			e->horizon -= y * 2;
			e->draw.skybox_y -= y * 2;
		}
	}
	else if (y < 0)
	{
		if (e->horizon < 1000)
		{
			e->horizon -= y * 2;
			e->draw.skybox_y -= y * 2;
		}
	}
	angle_overflow(&e->player.angle, e);
	if (e->draw.skybox_x > 1199)
		e->draw.skybox_x = 0;
	else if (e->draw.skybox_x < 0)
		e->draw.skybox_x = 1199;
	e->prev_mouse.x = e->event.motion.x;
	e->prev_mouse.y = e->event.motion.y;
}
