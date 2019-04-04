/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_main_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:36 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/04 18:17:15 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	clear_buffer(t_env *e)
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

void	world_interaction(t_env *e)
{
	move_player(e);
	weapon_fire(e);
	weapon_switch(e);
	animations(e);
}

void	renderer(t_env *e)
{
	clear_buffer(e);
	moving_rects(e);
	if (e->horizon > 0)
		display_skybox(e);
	multithreaded_render(e);
	draw_sprites(e);
	//draw_ui_base(e);
	//draw_ui(e);
	e->draw.str = ft_itoa(1 / e->time.frame_time);
	e->draw.fps_surface = \
	TTF_RenderText_Solid(e->draw.font, e->draw.str, e->draw.white);
	SDL_BlitSurface(e->draw.fps_surface, NULL, e->screen, NULL);
	SDL_FreeSurface(e->draw.fps_surface);
	ft_strdel(&e->draw.str);
	e->draw.skybox_x += 0.2;
	if (e->draw.skybox_x > 1226)
		e->draw.skybox_x = 0;
	minimap(e);
	e->ui.weapon_fired = 0;
	SDL_UpdateWindowSurface(e->win);
}

void	engine_loop(t_env *e)
{
	e->state = SDL_GetKeyboardState(NULL);
//	load_screen(e);
//	ft_menu(e);
	while (1)
	{
		e->time.new_time = SDL_GetTicks();
		e->time.frame_time = (e->time.new_time - e->time.last_time) / 1000.0;
		if (e->time.frame_time >= e->time.max_time)
		{
			e->time.delta_time = e->time.frame_time * 100;
			e->time.last_time = e->time.new_time;
			while (SDL_PollEvent(&e->event))
			{
				if (e->event.type == SDL_QUIT || e->state[SDL_SCANCODE_ESCAPE])
				{
					//ft_menu(e);
					exit (0);
				}
				(e->event.type == SDL_MOUSEMOTION) ? mouse_aim(e) : 0;
			}
			world_interaction(e);
			renderer(e);
		}
	}
}
