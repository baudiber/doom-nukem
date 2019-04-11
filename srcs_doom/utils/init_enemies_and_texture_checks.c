/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies_and_texture_checks.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:50:09 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/11 02:32:36 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	load_death_textures(t_env *e)
{
	if (!(e->files.image[41] = SDL_LoadBMP("textures/sprites/SERGE_D0.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[42] = SDL_LoadBMP("textures/sprites/SERGE_D1.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[43] = SDL_LoadBMP("textures/sprites/SERGE_D2.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[44] = SDL_LoadBMP("textures/sprites/SERGE_D3.bmp")))
		exit_error(2, ERR_2);
	if (!(e->files.image[45] = SDL_LoadBMP("textures/sprites/SERGE_D4.bmp")))
		exit_error(2, ERR_2);
}

void	rest_of_texture_pointing(t_env *e)
{
	e->files.ui = (unsigned int *)e->files.ui_surf->pixels;
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
