/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <baudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 19:09:47 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/12 00:49:23 by clrichar         ###   ########.fr       */
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

void			get_jump_pos(t_env *e, t_point *new_pos, double *fall_time)
{
	float g;
	g = 9;
	if (e->player.falling)
	{
		*fall_time += e->time.frame_time;
		e->player.height += -0.5 * g * pow(*fall_time, 2) + \
			*fall_time * (e->player.speed * 5) * e->sin_table[e->angle.a_270];
	}
//	if (e->player.falling)
//		e->player.height -= 5;
//	printf("player height = %d\nfloorheight = %d\n", e->player.height, (WALL_HEIGHT / 2) * (e->player.floor + 1));
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

void	jump_anim(t_env *e)
{
	static double	jump_time;
	printf ("ceil height = %d\n player height= %d\n", (e->player.floor + 1) * TILE_SIZE, e->player.height);
	//printf("floor_height = %d\nplayer_height = %d\n", (e->player.floor + 1) << e->tile_shift, e->player.height);
	if (e->player.jumping && jump_time <= 0.25 )
	{
		jump_time += e->time.frame_time;
		e->player.height += (e->player.speed + 3) * e->time.delta_time;
	}
	else
	{
		e->player.jumping = 0;
		jump_time = 0;
	}
}

void	get_floor_dist(t_env *e)
{
//	printf("player floor = %d\n", e->player.floor);
	if (e->player.map.x && e->player.map.y && e->player.floor && e->data.map[DWALL][e->player.floor - 1][e->player.map.y][e->player.map.x])
	{
//		printf("posy = %d\nposx=%d\n", (int)(e->player.pos.y + 32) >> e->tile_shift, (int)e->player.pos.x >> e->tile_shift);
//		printf("mapy = %d\nmapx=%d\n", e->player.map.y, e->player.map.x);
		e->player.dist_to_floor = e->player.floor * TILE_SIZE + WALL_HEIGHT / 2; 
	}
	else
		e->player.dist_to_floor = TILE_SIZE / 2;
//	printf("dist to floor = %d\n", e->player.dist_to_floor);
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
	collision(e, new_pos);
}

void			move_player(t_env *e)
{
	int			tmpangle;
	t_point		new_pos;
	static double fall_time;

	new_pos = e->player.pos;
//	printf("%f\n", e->player.pos.x);
	if (e->player.height <= e->player.dist_to_floor)
	{
		e->player.falling = 0;
		e->player.height = e->player.dist_to_floor;
	}
	else
		e->player.falling = 1;
//	printf("%d\n", e->player.falling);
	get_floor_dist(e);
	if (e->state[SDL_SCANCODE_LSHIFT])
	{
		e->player.speed = e->max_speed * 2;
		e->face_info.index = 3;
	}
	else
		e->player.speed = e->max_speed;
	if (e->state[SDL_SCANCODE_LCTRL] || e->state[SDL_SCANCODE_C] \
		|| (e->state[SDL_SCANCODE_SPACE] && !e->player.jumping && !e->player.falling))
		crouch_and_jump(e);
	jump_anim(e);
	if (!e->player.jumping && e->player.height > e->player.dist_to_floor)
		get_jump_pos(e, &new_pos, &fall_time);
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
	e->horizon -= y * 2;
	e->draw.skybox_y -= y * 2;
//	mouse_aim_x(e);
//	mouse_aim_y(e);
	angle_overflow(&e->player.angle, e);
	if (e->draw.skybox_x > 1199)
		e->draw.skybox_x = 0;
	else if (e->draw.skybox_x < 0)
		e->draw.skybox_x = 1199;
	e->prev_mouse.x = e->event.motion.x;
	e->prev_mouse.y = e->event.motion.y;
}
