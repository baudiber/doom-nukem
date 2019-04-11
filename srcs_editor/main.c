/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:41:40 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/11 18:45:42 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

static bool				basic_err(void)
{
	int					ret;

	ret = 0;
	if (ret == 0 && (MAX_SIZE < 1 || MAX_SIZE > 64))
		ret = 1;
	if (ret == 0 && MARGIN != 40)
		ret = 1;
	if (ret == 0 && (WIN_W < 320 && WIN_W > 1920))
		ret = 1;
	if (ret == 0 && (WIN_H < 200 && WIN_H > 1280))
		ret = 1;
	if (ret == 0 && TIER != 5)
		ret = 1;
	if (ret == 0 && TEX_SIZE != 256)
		ret = 1;
	if (ret == 0 && (DWALL != 0 || DFLOOR != 1 || DSPRITE != 2 || DLIGHT != 3 \
		|| DEVENT != 4))
		ret = 1;
	return (ret == 0) ? true : false;
}

static void			print_man(void)
{
	ft_putendl("");
	ft_putendl("\t\t*-------------------------------------------------------*");
	ft_putendl("\t\t|                                                       |");
	ft_putendl("\t\t|               Keybinding for the Editor               |");
	ft_putendl("\t\t|                                                       |");
	ft_putendl("\t\t|  Change panel: Tab                                    |");
	ft_putendl("\t\t|  Select a Texture: 1 - 9 key                          |");
	ft_putendl("\t\t|                                                       |");
	ft_putendl("\t\t|  To save current map: 's' key                         |");
	ft_putendl("\t\t|  To quit: 'echap' key                                 |");
	ft_putendl("\t\t|                                                       |");
	ft_putendl("\t\t|  Next Tier: Up Arrow       Previous Tier: Down Arrow  |");
	ft_putendl("\t\t|  Add Y axis: '*' key       Remove Y axis: '/' key     |");
	ft_putendl("\t\t|  Add X axis: '+' key       Remove X axis: '-' key     |");
	ft_putendl("\t\t|                                                       |");
	ft_putendl("\t\t*-------------------------------------------------------*");
	ft_putendl("");
}

void				exit_error(int type, char *msg)
{
	ft_putendl(msg);
	exit(type);
}

int		main(int ac, char **av)
{
	t_env		e;
	int		fd;

	if (!basic_err())
	{
		ft_putendl("ERROR: Please do not modify define in header file");
		return (0);
	}
	ft_bzero(&e, sizeof(t_env));
	e.tile_shift = 8;
	e.argc = ac;
	e.argv = av;
	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		if (fd == -1)
			init(&e);
		else
		{
//			e.parsed = 1;
			parse_start(&e.data, av[1]);
			init_from_parser(&e);
		}
		print_man();
		main_loop(&e);
	}
	else
		ft_putendl("Please give me the name of your map or the name of the map you want to open");
	return (0);
}
