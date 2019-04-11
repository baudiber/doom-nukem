/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:39 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/11 14:43:38 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rm -g in makefile
#include "doom_nukem.h"

t_env					*call(void)
{
	static t_env		e;
	return(&e);
}

static bool				basic_err(void)
{
	int					ret;

	ret = 0;
	if (FOV != 60)
		ret = 1;
	if (ret == 0 && (MAX_MAPSIZE < 1 || MAX_MAPSIZE > 64))
		ret = 1;
	if (ret == 0 && MAX_VISIBLE_SPRITE != 30)
		ret = 1;
	if (ret == 0 && (WIN_W < 320 && WIN_W > 1280))
		ret = 1;
	if (ret == 0 && (WIN_H < 200 && WIN_H > 800))
		ret = 1;
	if (ret == 0 && TILE_SIZE != 256)
		ret = 1;
	if (ret == 0 && (DWALL != 0 || DFLOOR != 1 || DSPRITE != 2 || DLIGHT != 3 \
		|| DEVENT != 4))
		ret = 1;
	return (ret == 0) ? true : false;
}

void				exit_error(int type, char *msg)
{
	ft_putendl(msg);
	exit(type);
}

int					main(int argc, char **argv)
{
	t_env			*e;

	e = call();
	if (argc != 2)
	{
		ft_putendl("usage : doom-nukem map_file");
		return (0);
	}
	if (!basic_err())
	{
		ft_putendl("ERROR: Please do not modify define in header file");
		return (0);
	}
	else if (argc == 2 && ft_strequ("", argv[1]))
		exit_error(7, ERR_BASE);
	ft_bzero(e, sizeof(t_env));
	parse_start(&e->data, argv[1]);
	parse_sprite(e);
	init_sdl(e);
	init_vars(e);
	init_player(e);
	load_textures(e);
	load_textures_menu(e);
	load_textures_splash(e);
	init_rects_and_font(e);
	init_ui_structs(e);
	init_sound(e);
	engine_loop(e);
	return (0);
}
