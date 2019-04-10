/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:39 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/10 14:26:00 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	init_rects_and_font(t_env *e)
{
	e->draw.font = TTF_OpenFont("font/BEBAS.ttf", 24);
	e->draw.white.a = 0;
	e->draw.white.r = 255;
	e->draw.white.g = 255;
	e->draw.white.b = 255;
	load_textures(e);
	load_textures_menu(e);
	e->draw.skybox_y = e->horizon - e->files.skybox->h;
}

void	load_textures_menu(t_env *e)
{
	e->menu.i_img = 0;
	//NOT SAFE
	e->menu.image[0] = SDL_LoadBMP("textures/menu/menu_newgame.bmp");
	e->menu.image[1] = SDL_LoadBMP("textures/menu/menu_options.bmp");
	e->menu.image[2] = SDL_LoadBMP("textures/menu/menu_quit.bmp");
	e->menu.image[3] = SDL_LoadBMP("textures/menu/72270.bmp");
	e->menu.image[4] = SDL_LoadBMP("textures/menu/options_!mute_0.bmp");
	e->menu.image[5] = SDL_LoadBMP("textures/menu/options_!mute_25.bmp");
	e->menu.image[6] = SDL_LoadBMP("textures/menu/options_!mute_50.bmp");
	e->menu.image[7] = SDL_LoadBMP("textures/menu/options_!mute_75.bmp");
	e->menu.image[8] = SDL_LoadBMP("textures/menu/options_!mute_100.bmp");
	e->menu.image[9] = SDL_LoadBMP("textures/menu/options_mute.bmp");
	e->menu.image[10] = SDL_LoadBMP("textures/load_screen/frame0.bmp");
	e->menu.image[11] = SDL_LoadBMP("textures/load_screen/frame1.bmp");
	e->menu.image[12] = SDL_LoadBMP("textures/load_screen/frame2.bmp");
	e->menu.image[13] = SDL_LoadBMP("textures/load_screen/frame3.bmp");
	e->menu.image[14] = SDL_LoadBMP("textures/load_screen/frame4.bmp");
	e->menu.image[15] = SDL_LoadBMP("textures/load_screen/frame5.bmp");
	e->menu.image[16] = SDL_LoadBMP("textures/load_screen/frame6.bmp");
	e->menu.image[17] = SDL_LoadBMP("textures/load_screen/frame7.bmp");
	e->menu.mute = 0;
	e->menu.save_img = 8;
}

void	load_gun_textures(t_env *e)
{
	if (!(e->files.image[17] = SDL_LoadBMP("textures/guns/pistol_f0.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[18] = SDL_LoadBMP("textures/guns/pistol_f1.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[19] = SDL_LoadBMP("textures/guns/pistol_f2.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[20] = SDL_LoadBMP("textures/guns/pistol_f3.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[21] = SDL_LoadBMP("textures/guns/pistol_f4.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[22] = SDL_LoadBMP("textures/guns/pistol_f5.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[23] = SDL_LoadBMP("textures/guns/shotgun_f0.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[24] = SDL_LoadBMP("textures/guns/shotgun_f1.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[25] = SDL_LoadBMP("textures/guns/shotgun_f2.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[26] = SDL_LoadBMP("textures/guns/shotgun_f3.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[27] = SDL_LoadBMP("textures/guns/shotgun_f4.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[28] = SDL_LoadBMP("textures/guns/shotgun_f5.bmp")))
		exit_error(2, ERR_2);
}

void	load_ui_textures(t_env *e)
{
	if (!(e->files.image[9] = SDL_LoadBMP("textures/UI/face.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[10] = SDL_LoadBMP("textures/UI/face2.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[11] = SDL_LoadBMP("textures/UI/face3.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[12] = SDL_LoadBMP("textures/UI/face_s.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[13] = SDL_LoadBMP("textures/UI/face_shoot.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[14] = SDL_LoadBMP("textures/UI/pistol_selec_ns.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[15] = SDL_LoadBMP("textures/UI/pistol_selec_s.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[16] = SDL_LoadBMP("textures/UI/shotgun_selec.bmp")))
		exit_error(2, ERR_2);
}

void	load_death_textures(t_env *e)
{
	if (!(e->files.image[29] = SDL_LoadBMP("textures/sprites/evil_sarge_d0"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[30] = SDL_LoadBMP("textures/sprites/evil_sarge_d1"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[31] = SDL_LoadBMP("textures/sprites/evil_sarge_d2"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[32] = SDL_LoadBMP("textures/sprites/evil_sarge_d3"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[33] = SDL_LoadBMP("textures/sprites/evil_sarge_d4"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
}

void	load_textures(t_env *e)
{
	if (!(e->files.skybox = SDL_LoadBMP("textures/skybox.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.ui_surf = SDL_LoadBMP("textures/UI/ui.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[0] = \
		SDL_LoadBMP("textures/walls/plates"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[1] = \
		SDL_LoadBMP("textures/walls/brown_metal"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[2] = \
		SDL_LoadBMP("textures/walls/warning"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[3] = \
		SDL_LoadBMP("textures/walls/bumpy"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[4] = SDL_LoadBMP("textures/floor"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[5] = SDL_LoadBMP("textures/sprites/evil_sarge"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[6] = SDL_LoadBMP("textures/sprites/shotgun"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[7] = SDL_LoadBMP("textures/sprites/barrel_0"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[8] = SDL_LoadBMP("textures/sprites/barrel_1"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[37] = SDL_LoadBMP("textures/walls/vent"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[38] = SDL_LoadBMP("textures/walls/GRATE.bmp")))
		exit_error(2, ERR_2);
	load_ui_textures(e);
	load_gun_textures(e);
	load_death_textures(e);
	if (!(e->files.image[34] = SDL_LoadBMP("textures/floor1"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	e->files.wall[1] = (unsigned int *)e->files.image[0]->pixels;
	e->files.wall[2] = (unsigned int *)e->files.image[1]->pixels;
	e->files.wall[3] = (unsigned int *)e->files.image[2]->pixels;
	e->files.wall[4] = (unsigned int *)e->files.image[3]->pixels;
	e->files.wall[5] = (unsigned int *)e->files.image[37]->pixels;
	e->files.wall[6] = (unsigned int *)e->files.image[38]->pixels;
	e->files.sprite[0] = (unsigned int *)e->files.image[5]->pixels;
	e->files.sprite[1] = (unsigned int *)e->files.image[6]->pixels;
	e->files.sprite[2] = (unsigned int *)e->files.image[7]->pixels;
	e->files.sprite[3] = (unsigned int *)e->files.image[8]->pixels;
	e->files.ui = (unsigned int *)e->files.ui_surf->pixels;
	e->files.face[0] = (unsigned int *)e->files.image[9]->pixels;
	e->files.face[1] = (unsigned int *)e->files.image[10]->pixels;
	e->files.face[2] = (unsigned int *)e->files.image[11]->pixels;
	e->files.face[3] = (unsigned int *)e->files.image[12]->pixels;
	e->files.face[4] = (unsigned int *)e->files.image[13]->pixels;
	e->files.inv[0] = (unsigned int *)e->files.image[14]->pixels;
	e->files.inv[1] = (unsigned int *)e->files.image[15]->pixels;
	e->files.inv[2] = (unsigned int *)e->files.image[16]->pixels;
	e->files.pistol[0] = (unsigned int *)e->files.image[17]->pixels;
	e->files.pistol[1] = (unsigned int *)e->files.image[18]->pixels;
	e->files.pistol[2] = (unsigned int *)e->files.image[19]->pixels;
	e->files.pistol[3] = (unsigned int *)e->files.image[20]->pixels;
	e->files.pistol[4] = (unsigned int *)e->files.image[21]->pixels;
	e->files.pistol[5] = (unsigned int *)e->files.image[22]->pixels;
	e->files.shotgun[0] = (unsigned int *)e->files.image[23]->pixels;
	e->files.shotgun[1] = (unsigned int *)e->files.image[24]->pixels;
	e->files.shotgun[2] = (unsigned int *)e->files.image[25]->pixels;
	e->files.shotgun[3] = (unsigned int *)e->files.image[26]->pixels;
	e->files.shotgun[4] = (unsigned int *)e->files.image[27]->pixels;
	e->files.shotgun[5] = (unsigned int *)e->files.image[28]->pixels;
	e->files.sprite[4] = (unsigned int *)e->files.image[29]->pixels;
	e->files.sprite[5] = (unsigned int *)e->files.image[30]->pixels;
	e->files.sprite[6] = (unsigned int *)e->files.image[31]->pixels;
	e->files.sprite[7] = (unsigned int *)e->files.image[32]->pixels;
	e->files.sprite[8] = (unsigned int *)e->files.image[33]->pixels;
	e->files.floor[0] = (unsigned int *)e->files.image[4]->pixels;
	e->files.floor[1] = (unsigned int *)e->files.image[34]->pixels;
	if (!(e->files.image[35] = SDL_LoadBMP("textures/floors/floor_trou"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[36] = SDL_LoadBMP("textures/floors/floor_joli"GRID_SIZE_STR".bmp")))
		exit_error(2, ERR_2);
	e->files.floor[2] = (unsigned int *)e->files.image[35]->pixels;
	e->files.floor[3] = (unsigned int *)e->files.image[36]->pixels;
	//CHECK texture size == TILE_SIZE
}
