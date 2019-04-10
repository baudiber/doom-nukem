/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:37:01 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 19:19:56 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	saving(t_env *e)
{
	int fd;
	int x;
	int y;
	int savetype;

	savetype = e->type;
	unlink(e->argv[1]);
	fd = open(e->argv[1], O_WRONLY | O_CREAT, 0644);
	y = -1;
	e->tier = -1;
	while (++e->tier < TIER)
	{
		y = -1;
		while (++y < e->grid.y)
		{
			x = -1;
			while (++x < e->grid.x)
			{
				e->type = 2;
				if (e->tab[e->type][e->tier][y][x] != 0)
				{
					if (e->tab[e->type][e->tier][y][x] == 1)
						ft_putchar_fd('z', fd);
					if (e->tab[e->type][e->tier][y][x] != 1)
						ft_putchar_fd((e->tab[e->type][e->tier][y][x] + 95), fd);
					else
						ft_putchar_fd(e->tab[e->type][e->tier][y][x], fd);
				}
				else
				{
					e->type = 0;
					ft_putnbr_fd(e->tab[e->type][e->tier][y][x], fd);
				}
				e->type = 1;
				ft_putchar_fd(',', fd);
				ft_putnbr_fd(e->tab[e->type][e->tier][y][x], fd);
				e->type = 3;
				ft_putchar_fd(',', fd);
				ft_putnbr_fd(e->tab[e->type][e->tier][y][x], fd);
				e->type = 4;
				ft_putchar_fd(',', fd);
				ft_putnbr_fd(e->tab[e->type][e->tier][y][x], fd);
				if (x != e->grid.x - 1)
					ft_putchar_fd(' ', fd);
				}
			ft_putchar_fd('\n', fd);
		}
		if (e->tier < TIER - 1)
			ft_putstr_fd("-\n", fd);
	}
	e->tier = 0;
	e->type = savetype;
}
