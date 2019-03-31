/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:39 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/31 18:47:01 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rm -g in makefile
#include "doom_nukem.h"

void					exit_error(int type)
{
	if (type == 1)
		ft_putendl("malloc failed to allocate memory");
	else if (type == 2)
		ft_putendl("Texture, Font or Audio file not found");
	else if (type == 3)
		ft_putendl("close() failed");
	else if (type == 4)
		ft_putendl("Error Loading audio");
	else if (type == 5)
		ft_putendl("SDL_LoadBMP error");
	else if (type == 6)
		ft_putendl("PLEASE PUT A SPAWN FOR THE PLAYER ('z')");
	else if (type == 7)
		ft_putendl("Map Error");
	else if (type == 8)
		ft_putendl("SDL Init Error");
	else if (type == 9)
		ft_putendl("Error open audio");
	else if (type == 10)
		ft_putendl("Too many sprites, please < 100 sprites");
	else if (type == 11)
		ft_putendl("FOV must be between 60 and 130");
	else if (type == 12)
		ft_putendl("GRID_SIZE MUST BE 64 || 128 || 256");
	exit(type);
}

int					main(int argc, char **argv)
{
	t_env			e;

	if (argc != 2)
	{
		ft_putstr("usage : Wolf3D map_file");
		return (0);
	}
	else if (argc == 2 && ft_strequ("", argv[1]))
		exit_error(7);

	ft_bzero(&e, sizeof(t_env));
	fake_parse(&e);
	init_sdl(&e);
	init_vars(&e);
	init_player(&e);
	init_rects_and_font(&e);
	init_ui_structs(&e);
	init_sound(&e);
	engine_loop(&e);
	return (0);
}
