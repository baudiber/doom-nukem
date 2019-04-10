/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:09:14 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 14:47:26 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		init_var_texture(t_e *e)
{
	e->texture.texture = 0;
	e->type = 0;
	e->tier = 0;
	e->texture.x = 0;
	e->texture.y = 0;
	// WARNING, GIVE THE TEXTURE TO e->texture.texture IN A SIDE MENU
}

void		load_texture(t_e *e)
{
	load_wall_texture(e);
	load_floor_texture(e);
	load_sprite_texture(e);
	e->texture.image[0] = SDL_LoadBMP("textures/editor_panel/editeur_panel_mur.bmp");
	e->texture.image[1] = SDL_LoadBMP("textures/editor_panel/editeur_panel_sol.bmp");
	e->texture.image[2] = SDL_LoadBMP("textures/editor_panel/editeur_panel_sprites.bmp");
	e->texture.image[3] = SDL_LoadBMP("textures/editor_panel/editeur_panel_lights.bmp");
	e->texture.image[4] = SDL_LoadBMP("textures/editor_panel/editeur_panel_event.bmp");
}

void		copy_texture(t_e *e)
{
	e->texture.tex[0] = (unsigned int *)e->texture.image[0]->pixels;
	e->texture.tex[1] = (unsigned int *)e->texture.image[1]->pixels;
	e->texture.tex[2] = (unsigned int *)e->texture.image[2]->pixels;
	e->texture.tex[3] = (unsigned int *)e->texture.image[3]->pixels;
	e->texture.tex[4] = (unsigned int *)e->texture.image[4]->pixels;
	e->texture.tex[5] = (unsigned int *)e->texture.image[5]->pixels;
	e->texture.tex[6] = (unsigned int *)e->texture.image[6]->pixels;
	e->texture.tex[7] = (unsigned int *)e->texture.image[7]->pixels;
	e->texture.tex[8] = (unsigned int *)e->texture.image[8]->pixels;
}
