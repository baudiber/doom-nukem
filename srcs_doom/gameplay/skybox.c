/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:56:01 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/13 21:24:14 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	draw_skybox(t_env *e)
{
	t_point		pos;
	int			tex_y;

	if (e->skybox_info.y_end > e->render_limit)
	{
		tex_y = e->files.skybox->h - (e->skybox_info.y_end - e->render_limit);
		pos.y = e->render_limit;
	}
	else 
	{
		tex_y = e->files.skybox->h - 1;
		pos.y = e->skybox_info.y_end;
	}
	while (tex_y > 0 && pos.y > 0)
	{
		pos.x = e->skybox_info.x_start - 1;
		while (++pos.x < WIN_W)
			e->buff[(int)pos.y * WIN_W + (int)pos.x] = e->files.sky[tex_y \
					* WIN_W + (int)pos.x];
		pos.y--;
		tex_y--;
	}
}
