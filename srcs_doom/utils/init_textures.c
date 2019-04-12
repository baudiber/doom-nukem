/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:50:09 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/12 18:21:46 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		load_gun_textures(t_env *e)
{
	if (!(e->files.image[0] = SDL_LoadBMP("textures/guns/PISTOL_0.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[1] = SDL_LoadBMP("textures/guns/PISTOL_1.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[2] = SDL_LoadBMP("textures/guns/PISTOL_2.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[3] = SDL_LoadBMP("textures/guns/PISTOL_3.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[4] = SDL_LoadBMP("textures/guns/PISTOL_4.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[5] = SDL_LoadBMP("textures/guns/PISTOL_5.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[6] = SDL_LoadBMP("textures/guns/SHOTGUN_0.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[7] = SDL_LoadBMP("textures/guns/SHOTGUN_1.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[8] = SDL_LoadBMP("textures/guns/SHOTGUN_2.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[9] = SDL_LoadBMP("textures/guns/SHOTGUN_3.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[10] = SDL_LoadBMP("textures/guns/SHOTGUN_4.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[11] = SDL_LoadBMP("textures/guns/SHOTGUN_5.bmp")))
		exit_error(2, ERR_2);
}

static void		load_ui_textures(t_env *e)
{
	if (!(e->files.image[12] = SDL_LoadBMP("textures/UI/FACE.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[13] = SDL_LoadBMP("textures/UI/FACE_2.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[14] = SDL_LoadBMP("textures/UI/FACE_3.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[15] = SDL_LoadBMP("textures/UI/FACE_S.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[16] = SDL_LoadBMP("textures/UI/FACE_C.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[17] = SDL_LoadBMP("textures/UI/PISTOL_SELEC_NS.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[18] = SDL_LoadBMP("textures/UI/PISTOL_SELEC_S.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[19] = SDL_LoadBMP("textures/UI/SHOTGUN_SELEC.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.ui_surf = SDL_LoadBMP("textures/UI/UI.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[47] = SDL_LoadBMP("textures/UI/UI_TRUMPET.bmp")))
		exit_error(2, ERR_2);
}

static void		load_sprite_textures(t_env *e)
{
	if (!(e->files.image[20] = SDL_LoadBMP("textures/sprites/SHOTGUN.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[21] = SDL_LoadBMP("textures/sprites/BARREL_0.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[22] = SDL_LoadBMP("textures/sprites/BARREL_1.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[23] = SDL_LoadBMP("textures/sprites/SERGE_BACK.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[24] = SDL_LoadBMP("textures/sprites/SERGE_RIGHT.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[25] = SDL_LoadBMP("textures/sprites/SERGE_LEFT.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[26] = SDL_LoadBMP("textures/sprites/SERGE_FRONT.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[27] = SDL_LoadBMP("textures/sprites/TRUMPET.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[48] = SDL_LoadBMP("textures/sprites/SKELETOR.bmp")))
		exit_error(2, ERR_2);
}

static void		load_walls_textures(t_env *e)
{
	if (!(e->files.image[28] = SDL_LoadBMP("textures/walls/ROCK.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[29] = SDL_LoadBMP("textures/walls/RUNES.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[30] = SDL_LoadBMP("textures/walls/METAL.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[31] = SDL_LoadBMP("textures/walls/CARVED.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[32] = SDL_LoadBMP("textures/walls/SPLASH.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[33] = SDL_LoadBMP("textures/walls/GRATE.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[34] = SDL_LoadBMP("textures/walls/VENT.bmp")))
		exit_error(2, ERR_2);
}

static void		load_floor_textures(t_env *e)
{
	if (!(e->files.image[35] = SDL_LoadBMP("textures/floors/STONE_TILE.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[36] = SDL_LoadBMP("textures/floors/JOLI.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[37] = SDL_LoadBMP("textures/floors/TROU.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[38] = SDL_LoadBMP("textures/floors/IS_LAVA.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[39] = SDL_LoadBMP("textures/floors/CEILING.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[40] = SDL_LoadBMP("textures/floors/CRACKLED.bmp")))
		exit_error(2, ERR_2);
}

void	load_textures(t_env *e)
{
	if (!(e->files.skybox = SDL_LoadBMP("textures/skybox.bmp")))
		exit_error(2, ERR_2);
	load_walls_textures(e);
	load_ui_textures(e);
	load_gun_textures(e);
	load_sprite_textures(e);
	load_death_textures(e);
	load_floor_textures(e);
	//check_textures_size(e);
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
	//shotgun
	e->files.sprite[4] = (unsigned int *)e->files.image[20]->pixels;
	//barrel
	e->files.sprite[5] = (unsigned int *)e->files.image[21]->pixels;
	//barrel 1
	e->files.sprite[6] = (unsigned int *)e->files.image[22]->pixels;
	//trumpet
	e->files.sprite[7] = (unsigned int *)e->files.image[27]->pixels;
	//SERGE FRONT 
	e->files.sprite[0] = (unsigned int *)e->files.image[26]->pixels;
	//serge b
	e->files.sprite[1] = (unsigned int *)e->files.image[23]->pixels;
	//serge r
	e->files.sprite[2] = (unsigned int *)e->files.image[24]->pixels;
	//serge l
	e->files.sprite[3] = (unsigned int *)e->files.image[25]->pixels;
	//death anim
	e->files.sprite[8] = (unsigned int *)e->files.image[41]->pixels;
	e->files.sprite[9] = (unsigned int *)e->files.image[42]->pixels;
	e->files.sprite[10] = (unsigned int *)e->files.image[43]->pixels;
	e->files.sprite[11] = (unsigned int *)e->files.image[44]->pixels;
	e->files.sprite[12] = (unsigned int *)e->files.image[45]->pixels;
	e->files.sprite[13] = (unsigned int *)e->files.image[48]->pixels;
	/////////////////
	e->files.face[0] = (unsigned int *)e->files.image[12]->pixels;
	e->files.face[1] = (unsigned int *)e->files.image[13]->pixels;
	e->files.face[2] = (unsigned int *)e->files.image[14]->pixels;
	e->files.face[3] = (unsigned int *)e->files.image[15]->pixels;
	e->files.face[4] = (unsigned int *)e->files.image[16]->pixels;
	//////////////////////
	e->files.inv[0] = (unsigned int *)e->files.image[17]->pixels;
	e->files.inv[1] = (unsigned int *)e->files.image[18]->pixels;
	e->files.inv[2] = (unsigned int *)e->files.image[19]->pixels;
	/////////////////////
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
	rest_of_texture_pointing(e);
	e->draw.skybox_y = e->horizon - e->files.skybox->h;
}
