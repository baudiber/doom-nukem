/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:03:42 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 19:11:17 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		load_wall_texture(t_env *e)
{
	e->texture.image[5] = SDL_LoadBMP("textures/walls/plates256.bmp");
	e->texture.image[6] = SDL_LoadBMP("textures/walls/brown_metal256.bmp");
	e->texture.image[7] = SDL_LoadBMP("textures/editor_textures/warning_editor.bmp");
}

void		load_floor_texture(t_env *e)
{
	e->texture.image[8] = SDL_LoadBMP("textures/floor256.bmp");
	e->texture.image[9] = SDL_LoadBMP("textures/floors/floor_joli256.bmp");
}

void		load_sprite_texture(t_env *e)
{
	e->texture.image[10] = SDL_LoadBMP("textures/editor_textures/player_spawn.bmp");
	e->texture.image[11] = SDL_LoadBMP("textures/editor_textures/item_shotgun.bmp");
}

void		load_light_texture(t_env *e)
{
	e->texture.image[12] = SDL_LoadBMP("textures/editor_textures/black_case.bmp");
}
