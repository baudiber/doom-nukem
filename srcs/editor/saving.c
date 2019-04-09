/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:37:01 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/09 18:11:54 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	saving(t_e *e)
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
				e->type = 0;
				ft_putnbr_fd(e->tab[e->type][e->tier][y][x], fd);
				e->type = 1;
				ft_putchar_fd(',', fd);
				ft_putnbr_fd(e->tab[e->type][e->tier][y][x], fd);
				e->type = 2;
				ft_putchar_fd(',', fd);
				if (e->tab[e->type][e->tier][y][x] >= 'a' && e->tab[e->type][e->tier][y][x] <= 'z')
					ft_putchar_fd(e->tab[e->type][e->tier][y][x], fd);
				else
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
			ft_putstr_fd("PROCHAINE LIGNE TABARNAK\n", fd);
	}
	e->tier = 0;
	e->type = savetype;
}
