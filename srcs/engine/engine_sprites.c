/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:32:39 by baudiber          #+#    #+#             */
/*   Updated: 2019/03/28 22:21:46 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_visible(t_env *e, t_sprite *sprite)
{
	t_sprite_draw	draw;
	int				x;

	get_screen_coord(e, &draw, sprite);
	while (++draw.start.y < draw.end.y)
	{
		x = draw.start.x - 1;
		draw.texture.y = (int)(draw.offset.y * draw.ratio);
		if (draw.texture.y > TILE_SIZE - 1)
			break ;
		draw.offset.x = draw.offsave;
		while (++x < draw.end.x)
		{
			if (check_walls(e, sprite->height, &draw.offset.x, x))
				continue ;
			draw.texture.x = (int)(draw.offset.x * draw.ratio);
			draw.color = e->files.sprite[sprite->tex][draw.texture.x \
			+ (draw.texture.y << e->tile_shift)];
			if ((draw.color ^ 0xFF00FFFF))
				e->buff[draw.start.y * WIN_W + x] = draw.color;
			draw.offset.x++;
		}
		draw.offset.y++;
	}
}

void	sort_sprites(t_env *e, t_sprite *farthest, int visnb, t_sprite *ptr)
{
	int			height;
	int			biggest;
	int			i;
	t_sprite	*step;
	t_sprite	*vis_start;

	vis_start = farthest;
	i = -1;
	while (++i < visnb)
	{
		biggest = ~0u >> 1;
		step = vis_start;
		while (step < ptr)
		{
			height = step->height;
			if (height < biggest)
			{
				biggest = height;
				farthest = step;
			}
			step++;
		}
		draw_visible(e, farthest);
		farthest->height = ~0u >> 1;
	}
}

void	change_tex(t_env *e, int nb)
{
	if (e->sprites[nb].tex == 2 || e->sprites[nb].tex == 3)
		e->sprites[nb].tex = 2 + e->barrel_tick;
	if (e->sprites[nb].dead && e->sprites[nb].dead < 8)
	{
		e->sprites[nb].dead += 0.1;
		e->sprites[nb].tex = (int)e->sprites[nb].dead;
	}
}

void	draw_sprites(t_env *e)
{
	t_sprite				visible[MAX_VISIBLE_SPRITE];
	t_sprite				*ptr;
	t_sprite_calculation	calc;
	int						sprite;
	int						visnb;

	ptr = &visible[0];
	sprite = -1;
	visnb = 0;
	while (++sprite < e->sprite_nb)
	{
		pick_up_obj(e, sprite);
		calc.map.x = e->sprites[sprite].x >> e->tile_shift;
		calc.map.y = e->sprites[sprite].y >> e->tile_shift;
		change_tex(e, sprite);
		if (!e->spotvis[calc.map.y][calc.map.x] || !e->sprites[sprite].visible)
			continue;
		else
		{
			++visnb;
			sprite_rotation(e, &calc, sprite);
			*ptr++ = e->sprites[sprite];
		}
	}
	sort_sprites(e, &visible[0], visnb, ptr);
}
