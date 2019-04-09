/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:41:40 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/09 16:45:39 by clrichar         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_e		e;
	int		fd;

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
