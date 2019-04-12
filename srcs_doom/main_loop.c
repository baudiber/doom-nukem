/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:36 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/13 01:04:22 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		clear_buffer(t_env *e)
{
	int			y;

	y = -1;
	while (++y < (e->render_limit * WIN_W))
	{
		if (y < e->horizon * WIN_W)
			e->buff[y] = 0;
		else
			e->buff[y] = 0xfeaa1b;
	}
	ft_bzero(&e->spotvis, sizeof(e->spotvis));
}

static void		get_floor_order(t_env *e)
{
	int		i;
	int		j;

	j = -1;
	i = 0;
	while (++j < e->player.floor)
		e->floor_order[i++] = j;
	j = e->floor_nb;
	while (--j >= e->player.floor)
		e->floor_order[i++] = j;
}

static void		world_interaction(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->sprite_nb)
		pick_up_obj(e, i);
	if (e->player.hp <= 0)
	{
		Mix_PlayChannel(-1, e->sound.sound8, 0);
		end_game(e, "WASTED");
	}
	get_player_floor(e);
	get_floor_order(e);
	move_player(e);
	weapon_fire(e);
	weapon_switch(e);
	animations(e);
}

static void		renderer(t_env *e)
{
	clear_buffer(e);
	moving_rects(e);
	if (e->horizon > 0)
		display_skybox(e);
//		draw_scaled(e, &e->skybox);
	multithreaded_render(e);
	draw_ui(e);
	e->draw.skybox_x += 0.2;
	if (e->draw.skybox_x > 1226)
		e->draw.skybox_x = 0;
	e->ui.weapon_fired = 0;
	SDL_UpdateWindowSurface(e->win);
}

void			engine_loop(t_env *e)
{
	e->state = SDL_GetKeyboardState(NULL);
	load_screen(e);
	ft_menu(e);
	while (true)
	{
		e->time.new_time = SDL_GetTicks();
		e->time.frame_time = (e->time.new_time - e->time.last_time) / 1000.0;
		if (e->time.frame_time >= e->time.max_time)
		{
			e->time.delta_time = e->time.frame_time * 100;
			e->time.last_time = e->time.new_time;
			while (SDL_PollEvent(&e->event))
			{
				if (e->event.type == SDL_QUIT \
					|| (e->event.key.keysym.sym == SDLK_ESCAPE \
					&& e->event.type == SDL_KEYDOWN))
				{
					e->menu.check = 0;
					ft_menu(e);
				}
				(e->event.type == SDL_MOUSEMOTION) ? mouse_aim(e) : 0;
			}
			if (!e->menu.check)
				ft_menu(e);
			world_interaction(e);
			renderer(e);
		}
	}
}
