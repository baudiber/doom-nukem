/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:03:42 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/09 20:08:01 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		load_wall_texture(t_e *e)
{
	e->texture.image[5] = SDL_LoadBMP("textures/walls/plates256.bmp");
	e->texture.image[6] = SDL_LoadBMP("textures/walls/brown_metal256.bmp");
	e->texture.image[7] = SDL_LoadBMP("textures/editor_textures/warning_editor.bmp");
}

void		load_floor_texture(t_e *e)
{
	(void)e;
}

void		load_sprite_texture(t_e *e)
{
	(void)e;
}
