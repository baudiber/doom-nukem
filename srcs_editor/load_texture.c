/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:03:42 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/11 02:40:08 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		load_wall_texture(t_env *e)
{
	if (!(e->texture.image[5] = SDL_LoadBMP("textures/walls/ROCK.bmp")))
		exit_error(2, ERR_2);
	if (!(e->texture.image[6] = SDL_LoadBMP("textures/walls/RUNES.bmp")))
		exit_error(2, ERR_2);
	if (!(e->texture.image[7] = SDL_LoadBMP("textures/walls/METAL.bmp")))
		exit_error(2, ERR_2);
	if (!(e->texture.image[8] = SDL_LoadBMP("textures/walls/CARVED.bmp")))
		exit_error(2, ERR_2);
	if (!(e->texture.image[9] = SDL_LoadBMP("textures/walls/SPLASH.bmp")))
		exit_error(2, ERR_2);
	if (!(e->texture.image[10] = SDL_LoadBMP("textures/walls/GRATE.bmp")))
		exit_error(2, ERR_2);
	if (!(e->texture.image[11] = SDL_LoadBMP("textures/walls/VENT.bmp")))
		exit_error(2, ERR_2);
}

void		load_floor_texture(t_env *e)
{
	if (!(e->texture.image[12] = SDL_LoadBMP("textures/floors/STONE_TILE.bmp")))
		exit_error(2, ERR_2);
	if (!(e->texture.image[13] = SDL_LoadBMP("textures/floors/JOLI.bmp")))
		exit_error(2, ERR_2);
	if (!(e->texture.image[14] = SDL_LoadBMP("textures/floors/TROU.bmp")))
		exit_error(2, ERR_2);
	if (!(e->texture.image[15] = SDL_LoadBMP("textures/floors/IS_LAVA.bmp")))
		exit_error(2, ERR_2);
	if (!(e->texture.image[16] = SDL_LoadBMP("textures/floors/CEILING.bmp")))
		exit_error(2, ERR_2);
	if (!(e->texture.image[17] = SDL_LoadBMP("textures/floors/CRACKLED.bmp")))
		exit_error(2, ERR_2);
}

void		load_sprite_texture(t_env *e)
{
	if (!(e->texture.image[18] = SDL_LoadBMP("textures/editor_textures/player_spawn.bmp")))
		exit_error(2, ERR_2);
	if (!(e->texture.image[19] = SDL_LoadBMP("textures/editor_textures/SARGE.bmp")))
		exit_error(2, ERR_2);
	if (!(e->texture.image[20] = SDL_LoadBMP("textures/editor_textures/item_shotgun.bmp")))
		exit_error(2, ERR_2);
}

void		load_light_texture(t_env *e)
{
	if (!(e->texture.image[21] = SDL_LoadBMP("textures/editor_textures/SHADOW.bmp")))
		exit_error(2, ERR_2);
}
