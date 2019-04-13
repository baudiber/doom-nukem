/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:56:01 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/13 22:01:16 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	draw_skybox(t_env *e)
{
	t_point		pos;
	t_point_int	tex;

	if (e->skybox_info.y_end > e->render_limit)
	{
		tex.y = e->files.skybox->h - (e->skybox_info.y_end - e->render_limit);
		pos.y = e->render_limit;
	}
	else 
	{
		tex.y = e->files.skybox->h - 1;
		pos.y = e->skybox_info.y_end;
	}
	while (tex.y > 0 && pos.y > 0)
	{
		tex.x = e->skybox_info.x_start - 1;
		pos.x = -1;
		while (++pos.x < WIN_W && pos.x >= 0)
		{
			if (tex.x >= WIN_W)
				tex.x = 0;
			e->buff[(int)pos.y * WIN_W + (int)pos.x] = e->files.sky[tex.y \
					* WIN_W + (int)tex.x];
			tex.x++;
		}
		pos.y--;
		tex.y--;
	}
}
