/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:40:17 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/11 16:44:32 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

static void		copy_from_parser(t_env *e)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < TIER)
		{
			k = -1;
			while (++k < MAX_SIZE)
			{
				l = -1;
				while (++l < MAX_SIZE)
				{
					e->tab[i][j][k][l] = e->data.map[i][j][k][l];
					if (e->data.map[i][j][k][l] == 'z')
						e->tab[i][j][k][l] = 1;
					if (e->data.map[i][j][k][l] >= 'a' && e->data.map[i][j][k][l] <= 'e')
						e->tab[i][j][k][l] = e->data.map[i][j][k][l] - 95;
				}
			}
		}
	}
}

void		init_from_parser(t_env *e)
{
	e->parsed = 1;
	init(e);
	copy_from_parser(e);
}
