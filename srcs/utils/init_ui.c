/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <baudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:47:32 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/10 12:35:28 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void	init_guns(t_env *e)
{
	e->pistol_info.x_start = WIN_W * 0.5 - WIN_W / 3.82 * 0.5;
	e->pistol_info.y_start = e->render_limit - (e->render_limit / 1.451);
	e->pistol_info.y_start += e->pistol_info.y_start * 0.25;
	e->pistol_info.y_ratio = e->files.image[17]->h / (e->render_limit / 1.451);
	e->pistol_info.x_ratio = e->files.image[17]->w / (WIN_W / 3.82);
	e->pistol_info.x_end = e->inv_info.x_start + WIN_W / 3.82;
	e->pistol_info.y_end = e->render_limit;
	e->pistol_info.buffer = &e->files.pistol[0];
	e->pistol_info.w = e->files.image[17]->w;
	e->ui.pistol_ystart = e->pistol_info.y_start;
	e->shotgun_info.x_start = WIN_W * 0.5 - WIN_W / 2.5004 * 0.5;
	e->shotgun_info.y_start = e->render_limit - (e->render_limit / 0.989);
	e->shotgun_info.y_start += fabs(e->shotgun_info.y_start) * 3;
	e->shotgun_info.y_ratio = e->files.image[23]->h / (e->render_limit / 0.989);
	e->shotgun_info.x_ratio = e->files.image[23]->w / (WIN_W / 2.5004);
	e->shotgun_info.x_end = e->shotgun_info.x_start + WIN_W / 2.5004;
	e->shotgun_info.y_end = e->render_limit;
	e->shotgun_info.buffer = &e->files.shotgun[0];
	e->shotgun_info.w = e->files.image[23]->w;
	e->ui.shotgun_ystart = e->shotgun_info.y_start;
}

void		init_base_ui(t_env *e)
{
	e->ui_info.x_start = 0;
	e->ui_info.y_start = e->render_limit - 1;
	e->ui_info.y_ratio = (double)(e->files.ui_surf->h / (double)e->ui.ui_size);
	e->ui_info.x_ratio = (double)(e->files.ui_surf->w / (double)WIN_W);
	e->ui_info.x_end = WIN_W;
	e->ui_info.y_end = WIN_H;
	e->ui_info.buffer = &e->files.ui;
	e->ui_info.w = e->files.ui_surf->w;
}

void		init_ui_structs(t_env *e)
{
	e->face_info.x_start = WIN_W * 0.5 - WIN_W / 12.0 * 0.5;
	e->face_info.y_start = e->render_limit * 1.005;
	e->face_info.y_ratio = (double)(e->files.image[9]->h / ((double)e->ui.ui_size \
							* 0.975));
	e->face_info.x_ratio = e->files.image[9]->w / (WIN_W / 12.0);
	e->face_info.x_end = e->face_info.x_start + WIN_W / 12.0;
	e->face_info.y_end = (double)(e->face_info.y_start + ((double)e->ui.ui_size * 0.975));
	e->face_info.buffer = &e->files.face[0];
	e->face_info.w = e->files.image[9]->w;
	e->inv_info.x_start = WIN_W / 3.02;
	e->inv_info.y_start = e->render_limit * 1.015;
	e->inv_info.y_ratio = e->files.image[14]->h / (WIN_H / 9.195);
	e->inv_info.x_ratio = e->files.image[14]->w / (WIN_W / 8.65);
	e->inv_info.x_end = e->inv_info.x_start + WIN_W / 8.65;
	e->inv_info.y_end = e->inv_info.y_start + WIN_H / 9.195;
	e->inv_info.buffer = &e->files.inv[0];
	e->inv_info.w = e->files.image[14]->w;
	init_guns(e);
	init_base_ui(e);
}
