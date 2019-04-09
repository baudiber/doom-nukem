/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:39 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/09 19:37:39 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rm -g in makefile
#include "doom_nukem.h"

t_env					*call(void)
{
	static t_env		e;
	return(&e);
}

void		exit_error(int type, char *msg)
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
	else if (argc == 2 && ft_strequ("", argv[1]))
		exit_error(7, ERR_BASE);
	ft_bzero(e, sizeof(t_env));
//	fake_parse(&e);
	parse_start(&e->data, argv[1]);
	parse_sprite(e);
	init_sdl(e);
	init_vars(e);
	init_player(e);
	init_rects_and_font(e);
	init_ui_structs(e);
	init_sound(e);
	engine_loop(e);
	return (0);
}
