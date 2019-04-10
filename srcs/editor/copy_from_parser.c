/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_from_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:09:25 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 17:36:57 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void			copy_from_parser(t_env *e)
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
				}
			}
		}
	}
}
