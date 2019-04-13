/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_sprite_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:44:04 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/13 22:25:22 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void	clip_start(int *start, int *offset)
{
	if (*start < 0)
	{
		*offset = -(*start);
		*start = 0;
	}
	else
		*offset = 0;
}

static void	clip_end(int *end, int y)
{
	if (y)
	{
		if (*end > y)
			*end = y;
	}
	else
	{
		if (*end > WIN_W)
			*end = WIN_W;
	}
}

void		change_tex(t_env *e, int nb)
{
	if (e->sprites[nb].dead && e->sprites[nb].dead < 12)
	{
		e->sprites[nb].dead += e->time.frame_time * 0.5;
		e->sprites[nb].tex = (int)e->sprites[nb].dead;
	}
}

void		get_screen_coord(t_env *e, t_sprite_draw *draw, t_sprite *sprite, \
	int tid)
{
	draw->ratio = (float)TILE_SIZE / sprite->height;
	draw->end.y = ceil(((e->player.plane_dist / sprite->dist) \
		* e->player.height + e->horizon) - sprite->height * e->ray[tid].layer);
	draw->start.y = draw->end.y - sprite->height;
	clip_start(&draw->start.y, &draw->offset.y);
	draw->start.y--;
	clip_end(&draw->end.y, e->render_limit);
	draw->start.x = sprite->screen_x - (sprite->height / 2);
	draw->end.x = draw->start.x + sprite->height;
	clip_start(&draw->start.x, &draw->offsave);
	clip_end(&draw->end.x, 0);
}

void		sprite_rotation(t_env *e, t_sprite_calculation *calc, int nb)
{
	int		spread;

	spread = e->ui.weapon ? 50.0 : 100.0;
	calc->r.x = e->sprites[nb].x - e->player.pos.x;
	calc->r.y = e->sprites[nb].y - e->player.pos.y;
	calc->t.x = calc->r.x * e->sin_table[e->player.angle] \
	- calc->r.y * e->cos_table[e->player.angle];
	calc->t.y = calc->r.x * e->cos_table[e->player.angle] \
	+ calc->r.y * e->sin_table[e->player.angle];
	e->sprites[nb].dist = calc->t.y;
	if (fabs(calc->t.x) < spread && e->ui.weapon_fired && !e->sprites[nb].dead \
			&& e->sprites[nb].tex < 4)
		e->sprites[nb].dead = 8;
	calc->height = TILE_SIZE * e->player.plane_dist / calc->t.y;
	e->sprites[nb].height = calc->height;
	calc->screen_x = (WIN_W / 2 - calc->t.x / TILE_SIZE * calc->height);
	e->sprites[nb].screen_x = calc->screen_x;
}
