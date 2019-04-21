/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:50:09 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/13 15:59:04 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		load_gun_textures(t_env *e)
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

void		load_ui_textures(t_env *e)
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

void		load_sprite_textures(t_env *e)
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
	if (!(e->files.image[49] = SDL_LoadBMP("textures/sprites/HEALTH_PACK.bmp")))
		exit_error(2, ERR_2);
}

void		load_walls_textures(t_env *e)
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

void		load_floor_textures(t_env *e)
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
