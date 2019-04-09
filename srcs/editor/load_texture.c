/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:03:42 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/09 16:45:39 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		load_wall_texture(t_e *e)
{
	e->texture.image[5] = SDL_LoadBMP("textures/walls/plates.bmp");
	e->texture.image[6] = SDL_LoadBMP("textures/walls/brown_metal.bmp");
	e->texture.image[7] = SDL_LoadBMP("textures/walls/warning_editor.bmp");
}

void		load_floor_texture(t_e *e)
{
	(void)e;
}

void		load_sprite_texture(t_e *e)
{
	(void)e;
}
