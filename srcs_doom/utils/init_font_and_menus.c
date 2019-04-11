/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_font_and_menus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:50:09 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/11 14:46:46 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	init_rects_and_font(t_env *e)
{
	if (!(e->draw.font = TTF_OpenFont("font/BEBAS.ttf", 24)))
		exit_error(2, ERR_2);
	e->draw.white.a = 0;
	e->draw.white.r = 255;
	e->draw.white.g = 255;
	e->draw.white.b = 255;
}

void	load_textures_splash(t_env *e)
{
	if (!(e->menu.image[10] = SDL_LoadBMP("textures/load_screen/frame0.bmp")))
		exit_error(2, ERR_2);
	if (!(e->menu.image[11] = SDL_LoadBMP("textures/load_screen/frame1.bmp")))
		exit_error(2, ERR_2);
	if (!(e->menu.image[12] = SDL_LoadBMP("textures/load_screen/frame2.bmp")))
		exit_error(2, ERR_2);
	if (!(e->menu.image[13] = SDL_LoadBMP("textures/load_screen/frame3.bmp")))
		exit_error(2, ERR_2);
	if (!(e->menu.image[14] = SDL_LoadBMP("textures/load_screen/frame4.bmp")))
		exit_error(2, ERR_2);
	if (!(e->menu.image[15] = SDL_LoadBMP("textures/load_screen/frame5.bmp")))
		exit_error(2, ERR_2);
	if (!(e->menu.image[16] = SDL_LoadBMP("textures/load_screen/frame6.bmp")))
		exit_error(2, ERR_2);
	if (!(e->menu.image[17] = SDL_LoadBMP("textures/load_screen/frame7.bmp")))
		exit_error(2, ERR_2);
}

void	load_textures_menu(t_env *e)
{
	e->menu.i_img = 0;
	if (!(e->menu.image[0] = SDL_LoadBMP("textures/menu/menu_newgame.bmp")))
		exit_error(2, ERR_2);
	if (!(e->menu.image[1] = SDL_LoadBMP("textures/menu/menu_options.bmp")))
		exit_error(2, ERR_2);
	if (!(e->menu.image[2] = SDL_LoadBMP("textures/menu/menu_quit.bmp")))
		exit_error(2, ERR_2);
	//removed image 3
	if (!(e->menu.image[4] = SDL_LoadBMP("textures/menu/options_!mute_0.bmp")))
		exit_error(2, ERR_2);
	if (!(e->menu.image[5] = SDL_LoadBMP("textures/menu/options_!mute_25.bmp")))
		exit_error(2, ERR_2);
	if (!(e->menu.image[6] = SDL_LoadBMP("textures/menu/options_!mute_50.bmp")))
		exit_error(2, ERR_2);
	if (!(e->menu.image[7] = SDL_LoadBMP("textures/menu/options_!mute_75.bmp")))
		exit_error(2, ERR_2);
	if (!(e->menu.image[8] = \
				SDL_LoadBMP("textures/menu/options_!mute_100.bmp")))
		exit_error(2, ERR_2);
	if (!(e->menu.image[9] = SDL_LoadBMP("textures/menu/options_mute.bmp")))
		exit_error(2, ERR_2);
	e->menu.mute = 0;
	e->menu.save_img = 8;
}
