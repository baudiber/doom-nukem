/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:56:01 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/14 00:12:37 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void			check_skybox(t_env *e, t_point_int *tex, t_point *pos)
{
	if (e->skybox_info.y_end > e->render_limit)
	{
		tex->y = e->files.skybox->h - (e->skybox_info.y_end - e->render_limit);
		pos->y = e->render_limit;
	}
	else
	{
		tex->y = e->files.skybox->h - 1;
		pos->y = e->skybox_info.y_end;
	}
}

void				draw_skybox(t_env *e)
{
	t_point			pos;
	t_point_int		tex;

	ft_bzero(&pos, sizeof(pos));
	ft_bzero(&tex, sizeof(tex));
	check_skybox(e, &tex, &pos);
	while (tex.y > 0 && pos.y > 0)
	{
		tex.x = e->skybox_info.x_start - 1;
		pos.x = -1;
		while (++pos.x < WIN_W && pos.x >= 0)
		{
			tex.x = (tex.x >= WIN_W) ? 0 : tex.x;
			e->buff[(int)pos.y * WIN_W + (int)pos.x] = e->files.sky[tex.y \
				* WIN_W + (int)tex.x];
			tex.x++;
		}
		pos.y--;
		tex.y--;
	}
}
