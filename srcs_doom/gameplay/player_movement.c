/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <baudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 19:09:47 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/12 05:59:47 by gagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

bool			is_blocked(t_env *e, t_point *new_pos, int y)
{
	t_point_int		pt;

	pt.x = (int)new_pos->x >> e->tile_shift;
	pt.y = (int)new_pos->y >> e->tile_shift;
	if (!ray_is_in_the_map(pt, e))
		return (false);
	if (y)
	{
		if (e->data.map[DWALL][e->player.floor][pt.y][e->player.map.x])
			return (true);
	}
	else if (!y)
	{
		if (e->data.map[DWALL][e->player.floor][e->player.map.y][pt.x])
			return (true);
	}
	return (false);
}

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
int		get_ceil_height(t_env *e)
{
	int i;
	int ceil_height;

	ceil_height = 0;
	i = 1;
	while (i < (int)e->floor_nb)
	{
		if (e->data.map[DWALL][e->player.floor + i][e->player.map.y][e->player.map.x])
		{
			ceil_height = (e->player.floor + i) * TILE_SIZE;
			return (ceil_height);
		}
		i++;
	}
	i--;
	return (((int)e->floor_nb - 1 ) * TILE_SIZE);
}

void	jump_anim(t_env *e)
{
	static double	jump_time;
	int				ceil_height;
	
	ceil_height = get_ceil_height(e);
	if (e->player_state & IS_FLY)
		return ;
	if((e->player_state & IS_JUMPING) && e->data.map[DWALL][e->player.floor + 1][e->player.map.y][e->player.map.x])
	{
		if (e->player.height >= ceil_height - 20)
			e->player_state &= (0 << 2);
	}
	if ((e->player_state & IS_JUMPING) && jump_time <= 0.28)
	{
		jump_time += e->time.frame_time;
	if(e->player.height < ceil_height)
		e->player.height += (e->max_speed + 3) * e->time.delta_time;
	}
	else
	{
		e->player_state &= (0 << 2);
		e->player_state |= IS_FALLING;
		jump_time = 0;
	}
}

void	get_floor_dist(t_env *e)
{
	if (e->player.map.x && e->player.map.y && e->player.floor && e->data.map[DWALL][e->player.floor - 1][e->player.map.y][e->player.map.x])
		e->player.dist_to_floor = e->player.floor * TILE_SIZE + WALL_HEIGHT / 2; 
	else
		e->player.dist_to_floor = TILE_SIZE / 2;
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
	int			tmpangle;
	t_point		new_pos;
	static double fall_time;

	new_pos = e->player.pos;
	if (e->state[SDL_SCANCODE_F])
		e->player_state ^= IS_FLY;
	if (e->player.height <= e->player.dist_to_floor && !(e->player_state & IS_FLY))
	{
		e->player_state &= (0 << 4);
		e->player.height = e->player.dist_to_floor;
	}
	else
		e->player_state |= IS_FALLING;
	get_floor_dist(e);
	if (e->state[SDL_SCANCODE_LSHIFT])
	{
		e->player.speed = e->max_speed * 2;
		e->face_info.index = 3;
	}
	else
		e->player.speed = e->max_speed;
	if (((e->state[SDL_SCANCODE_LCTRL] || e->state[SDL_SCANCODE_C]) && !(e->player_state & IS_FLY)) \
		|| (e->state[SDL_SCANCODE_SPACE] && !(e->player_state & IS_JUMPING) && !(e->player_state & IS_FALLING) && !(e->player_state & IS_FLY)))
		crouch_and_jump(e);
	if (((e->state[SDL_SCANCODE_LCTRL] || e->state[SDL_SCANCODE_C]) && e->player_state & IS_FLY) \
		|| (e->state[SDL_SCANCODE_SPACE] && e->player_state & IS_FLY))
		fly_mode(e);
	jump_anim(e);
	if (!(e->player_state & IS_JUMPING) && e->player.height > e->player.dist_to_floor)
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
