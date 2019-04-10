/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:41:40 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 14:38:40 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void		exit_error(int type)
{
	if (type == 1)
		ft_putendl("SDL Init Error");
	else if (type == 2)
		ft_putendl("Error Malloc of e->tab[e->type][e->tier] in init_tab(t_e *)");
	else if (type == 3)
		ft_putendl("Error Malloc of tmp_tab in malloc_tmp_tab(t_e *, int **)");
	exit(type);
}

static bool				basic_err(void)
{
	int					ret;

	ret = 0;
	if (FOV != 60)
		ret = 1;
	if (ret == 0 && (MAX_SIZE < 1 || MAX_MAPSIZE > 64))
		ret = 1;
	if (ret == 0 && margin != 40)
		ret = 1;
	if (ret == 0 && (WIN_W < 320 && WIN_W > 1920))
		ret = 1;
	if (ret == 0 && (WIN_H < 200 && WIN_H > 1280))
		ret = 1;
	if (ret == 0 && TIER != 5)
		ret = 1;
	if (ret == 0 && TILE_SIZE != 256)
		ret = 1;
	if (ret == 0 && (DWALL != 0 || DFLOOR != 1 || DSPRITE != 2 || DLIGHT != 3 \
		|| DEVENT != 4))
		ret = 1;
	return (ret == 0) ? true : false;
}

int		main(int ac, char **av)
{
	t_e		e;
	int		fd;

	if (!basic_err())
	{
		ft_putendl("ERROR: Please do not modify define in header file");
		return (0);
	}
	// a revoir
	e.argc = ac;
	e.argv = av;
	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		if (fd == -1)
			init(&e);
		else
		{
			//NEED TO INIT FROM PARSING
		}
		engine_loop(&e);
	}
	else
		ft_putendl("Please give me the name of your map or the name of the map you want to open");
	return (0);
}
