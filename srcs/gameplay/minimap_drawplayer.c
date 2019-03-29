/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_drawplayer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:17:58 by roddavid          #+#    #+#             */
/*   Updated: 2019/03/25 17:58:13 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_player_small(t_env *e)
{
	int j;
	int i;
	float padx;
	float pady;

	pady = (float)UI_Y2 / (float)(e->data.max_y);
	padx = (float)UI_Y2 / (float)(e->data.max_x);
	j = pady * (e->player.pos.y / TILE_SIZE) + 495;
	while (j < (pady * ((e->player.pos.y / TILE_SIZE) + 1) + 495 \
	- (pady / 2)) && j < (WIN_H))
	{
		i = padx * (e->player.pos.x / TILE_SIZE) + 975;
		while (i < (padx * ((e->player.pos.x / TILE_SIZE) + 1) + 975 \
		- (padx / 2)) && i < WIN_W)
		{
			e->buff[WIN_W * (j + ((int)pady / 2)) \
				+ (i + ((int)padx / 2))] = 0xFFFF00;
			i++;
		}
		j++;
	}
}

void		draw_player_big(t_env *e)
{
	int j;
	int i;
	float padx;
	float pady;

	pady = (float)e->render_limit / (float)(e->data.max_y);
	padx = (float)e->render_limit / (float)(e->data.max_x);
	j = pady * (e->player.pos.y / TILE_SIZE) - 10;
	while (j < (pady * ((e->player.pos.y / TILE_SIZE) + 1) - 10 \
	- (pady / 2)) && j < (e->render_limit))
	{
		i = padx * (e->player.pos.x / TILE_SIZE) + 294;
		while (i < (padx * ((e->player.pos.x / TILE_SIZE) + 1) + 294 \
		- (padx / 2)) && i < WIN_W)
		{
			e->buff[WIN_W * (j + ((int)pady / 2)) \
				+ (i + ((int)padx / 2))] = 0xFFFF00;
			i++;
		}
		j++;
	}
}
