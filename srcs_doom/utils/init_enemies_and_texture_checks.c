/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies_and_texture_checks.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:50:09 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/11 02:10:49 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	load_enemy_textures(t_env *e)
{
	if (!(e->files.image[29] = SDL_LoadBMP("textures/sprites/SERGE_D0.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[30] = SDL_LoadBMP("textures/sprites/SERGE_D1.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[31] = SDL_LoadBMP("textures/sprites/SERGE_D2.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[32] = SDL_LoadBMP("textures/sprites/SERGE_D3.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[33] = SDL_LoadBMP("textures/sprites/SERGE_D4.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[5] = SDL_LoadBMP("textures/sprites/SERGE_D5.bmp")))
		exit_error(2, ERR_2);
}

void	rest_of_texture_pointing(t_env *e)
{
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
}

void	check_textures_size(t_env *e)
{
	int					i;

	i = -1;
	while (++i < 9)
	{
		if (e->files.image[i]->w != TILE_SIZE \
				|| e->files.image[i]->h != TILE_SIZE)
			exit_error(2, ERR_0);
	}
}
