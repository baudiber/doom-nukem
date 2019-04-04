/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <baudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 19:09:47 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/03 19:25:33 by gagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

bool			is_blocked(t_env *e, t_point *new_pos, int y)
{
	if (!ray_is_in_the_map((int)new_pos->x >> e->tile_shift, \
		(int)new_pos->y >> e->tile_shift, e))
		return (false);
	if (y)
	{
		if (e->data.map[0][0][(int)new_pos->y >> e->tile_shift][e->player.map.x])
			return (true);
	}
	else if (!y)
	{
		if (e->data.map[0][0][e->player.map.y][(int)new_pos->x >> e->tile_shift])
			return (true);
	}
	return (false);
}

void			get_delta(int angle, t_env *e, t_point *new_pos)
{
	new_pos->x += e->cos_table[angle] * (e->player.speed * e->time.delta_time);
	new_pos->y += e->sin_table[angle] * (e->player.speed * e->time.delta_time);
}

void			get_jump_pos(t_env *e, t_point *new_pos)
{
	float g;
	g = 1.62;
	e->player.height += -0.5 * g * pow(e->time.delta_time, 2) + e->time.delta_time * e->player.speed * e->sin_table[e->angle.a_270];
	get_delta(e->player.angle, e, new_pos);
}

void			collision(t_env *e, t_point *new_pos)
{
	if (!is_blocked(e, new_pos, 0))
	{
		e->player.pos.x = new_pos->x;
		e->player.pace += 3;
	}
	if (!is_blocked(e, new_pos, 1))
	{
		e->player.pos.y = new_pos->y;
		e->player.pace += 3;
	}
	if (e->player.pace > 360)
		e->player.pace -= 360;
}

void			move_player(t_env *e)
{
	int			tmpangle;
	t_point		new_pos;

	new_pos = e->player.pos;
	if (e->player.height > WALL_HEIGHT / 2 && !e->state[SDL_SCANCODE_SPACE]) 
		get_jump_pos(e, &new_pos);
	if (e->state[SDL_SCANCODE_LSHIFT])
	{
		e->player.speed = e->max_speed * 2;
		e->face_info.index = 3;
	}
	else
	{
		e->player.speed = e->max_speed;
		if (!e->ui.weapon_firing)
			e->face_info.index = 0;
	}
	if (e->state[SDL_SCANCODE_LCTRL] || e->state[SDL_SCANCODE_C] \
		|| e->state[SDL_SCANCODE_SPACE])
		crouch_and_jump(e);
	if (e->state[SDL_SCANCODE_A] || e->state[SDL_SCANCODE_W] \
			|| e->state[SDL_SCANCODE_S] || e->state[SDL_SCANCODE_D])
		e->player.moving = true;
	else
	{
		e->player.moving = false;
		return ;
	}
	if ((e->state[SDL_SCANCODE_A] || e->state[SDL_SCANCODE_D]) \
	&& e->state[SDL_SCANCODE_W])
		strafe_forward(e, &new_pos, &tmpangle);
	else if (e->state[SDL_SCANCODE_S] && (e->state[SDL_SCANCODE_A] \
		|| e->state[SDL_SCANCODE_D]))
		strafe_backward(e, &new_pos, &tmpangle);
	else if (e->state[SDL_SCANCODE_A] || e->state[SDL_SCANCODE_D])
		strafe(e, &new_pos, &tmpangle);
	else if (e->state[SDL_SCANCODE_W] || e->state[SDL_SCANCODE_S])
		walk_forward_and_backward(e, &new_pos, &tmpangle);
	//collision(e, &new_pos);
	e->player.pos = new_pos;
}

void			mouse_aim(t_env *e)
{
	mouse_aim_x(e);
	mouse_aim_y(e);
	if (e->player.angle >= e->angle.a_360)
		e->player.angle -= e->angle.a_360;
	if (e->player.angle < 0)
		e->player.angle = e->angle.a_360 + e->player.angle;
	if (e->draw.skybox_x > 1199)
		e->draw.skybox_x = 0;
	else if (e->draw.skybox_x < 0)
		e->draw.skybox_x = 1199;
	e->prev_mouse.x = e->event.motion.x;
	e->prev_mouse.y = e->event.motion.y;
}
