/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:09:14 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/13 16:24:44 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

static void			next_copy(t_env *e)
{
	e->texture.tex[21] = (unsigned int *)e->texture.image[21]->pixels;
	e->texture.tex[22] = (unsigned int *)e->texture.image[22]->pixels;
	e->texture.tex[23] = (unsigned int *)e->texture.image[23]->pixels;
	e->texture.tex[24] = (unsigned int *)e->texture.image[24]->pixels;
	e->texture.tex[25] = (unsigned int *)e->texture.image[25]->pixels;
	e->texture.tex[26] = (unsigned int *)e->texture.image[26]->pixels;
}

static void			copy_texture(t_env *e)
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
	e->texture.tex[9] = (unsigned int *)e->texture.image[9]->pixels;
	e->texture.tex[10] = (unsigned int *)e->texture.image[10]->pixels;
	e->texture.tex[11] = (unsigned int *)e->texture.image[11]->pixels;
	e->texture.tex[12] = (unsigned int *)e->texture.image[12]->pixels;
	e->texture.tex[13] = (unsigned int *)e->texture.image[13]->pixels;
	e->texture.tex[14] = (unsigned int *)e->texture.image[14]->pixels;
	e->texture.tex[15] = (unsigned int *)e->texture.image[15]->pixels;
	e->texture.tex[16] = (unsigned int *)e->texture.image[16]->pixels;
	e->texture.tex[17] = (unsigned int *)e->texture.image[17]->pixels;
	e->texture.tex[18] = (unsigned int *)e->texture.image[18]->pixels;
	e->texture.tex[19] = (unsigned int *)e->texture.image[19]->pixels;
	e->texture.tex[20] = (unsigned int *)e->texture.image[20]->pixels;
	next_copy(e);
}

void				init_var_texture(t_env *e)
{
	e->texture.texture = 0;
	e->type = 0;
	e->tier = 0;
	e->texture.x = 0;
	e->texture.y = 0;
	load_texture(e);
	copy_texture(e);
}
