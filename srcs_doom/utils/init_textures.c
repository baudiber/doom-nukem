/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 01:11:49 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/13 01:18:13 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void			text_cpy_3(t_env *e)
{
	e->files.face[0] = (unsigned int *)e->files.image[12]->pixels;
	e->files.face[1] = (unsigned int *)e->files.image[13]->pixels;
	e->files.face[2] = (unsigned int *)e->files.image[14]->pixels;
	e->files.face[3] = (unsigned int *)e->files.image[15]->pixels;
	e->files.face[4] = (unsigned int *)e->files.image[16]->pixels;
	e->files.inv[0] = (unsigned int *)e->files.image[17]->pixels;
	e->files.inv[1] = (unsigned int *)e->files.image[18]->pixels;
	e->files.inv[2] = (unsigned int *)e->files.image[19]->pixels;
	e->files.pistol[0] = (unsigned int *)e->files.image[0]->pixels;
	e->files.pistol[1] = (unsigned int *)e->files.image[1]->pixels;
	e->files.pistol[2] = (unsigned int *)e->files.image[2]->pixels;
	e->files.pistol[3] = (unsigned int *)e->files.image[3]->pixels;
	e->files.pistol[4] = (unsigned int *)e->files.image[4]->pixels;
	e->files.pistol[5] = (unsigned int *)e->files.image[5]->pixels;
	e->files.shotgun[0] = (unsigned int *)e->files.image[6]->pixels;
	e->files.shotgun[1] = (unsigned int *)e->files.image[7]->pixels;
	e->files.shotgun[2] = (unsigned int *)e->files.image[8]->pixels;
	e->files.shotgun[3] = (unsigned int *)e->files.image[9]->pixels;
	e->files.shotgun[4] = (unsigned int *)e->files.image[10]->pixels;
	e->files.shotgun[5] = (unsigned int *)e->files.image[11]->pixels;
}

static void			text_cpy_2(t_env *e)
{
	e->files.sprite[4] = (unsigned int *)e->files.image[20]->pixels;
	e->files.sprite[5] = (unsigned int *)e->files.image[21]->pixels;
	e->files.sprite[6] = (unsigned int *)e->files.image[22]->pixels;
	e->files.sprite[7] = (unsigned int *)e->files.image[27]->pixels;
	e->files.sprite[0] = (unsigned int *)e->files.image[26]->pixels;
	e->files.sprite[1] = (unsigned int *)e->files.image[23]->pixels;
	e->files.sprite[2] = (unsigned int *)e->files.image[24]->pixels;
	e->files.sprite[3] = (unsigned int *)e->files.image[25]->pixels;
	e->files.sprite[8] = (unsigned int *)e->files.image[41]->pixels;
	e->files.sprite[9] = (unsigned int *)e->files.image[42]->pixels;
	e->files.sprite[10] = (unsigned int *)e->files.image[43]->pixels;
	e->files.sprite[11] = (unsigned int *)e->files.image[44]->pixels;
	e->files.sprite[12] = (unsigned int *)e->files.image[45]->pixels;
	e->files.sprite[13] = (unsigned int *)e->files.image[48]->pixels;
}

static void			text_cpy_1(t_env *e)
{
	e->files.wall[1] = (unsigned int *)e->files.image[28]->pixels;
	e->files.wall[2] = (unsigned int *)e->files.image[29]->pixels;
	e->files.wall[3] = (unsigned int *)e->files.image[30]->pixels;
	e->files.wall[4] = (unsigned int *)e->files.image[31]->pixels;
	e->files.wall[5] = (unsigned int *)e->files.image[32]->pixels;
	e->files.wall[6] = (unsigned int *)e->files.image[33]->pixels;
	e->files.wall[7] = (unsigned int *)e->files.image[34]->pixels;
	e->files.wall[8] = (unsigned int *)e->files.image[35]->pixels;
	e->files.floor[0] = (unsigned int *)e->files.image[35]->pixels;
	e->files.floor[1] = (unsigned int *)e->files.image[36]->pixels;
	e->files.floor[2] = (unsigned int *)e->files.image[37]->pixels;
	e->files.floor[3] = (unsigned int *)e->files.image[38]->pixels;
	e->files.floor[4] = (unsigned int *)e->files.image[39]->pixels;
	e->files.floor[5] = (unsigned int *)e->files.image[40]->pixels;
}

void				load_textures(t_env *e)
{
	if (!(e->files.skybox = SDL_LoadBMP("textures/skybox.bmp")))
		exit_error(2, ERR_2);
	load_walls_textures(e);
	load_ui_textures(e);
	load_gun_textures(e);
	load_sprite_textures(e);
	load_death_textures(e);
	load_floor_textures(e);
	text_cpy_1(e);
	text_cpy_2(e);
	text_cpy_3(e);
	rest_of_texture_pointing(e);
	e->draw.skybox_y = e->horizon - e->files.skybox->h;
}
