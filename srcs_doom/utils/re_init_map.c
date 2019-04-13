/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:33:40 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/14 00:12:36 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void			assign(t_data *data, int i, int j)
{
	int				k;
	int				l;

	k = -1;
	while (++k < 64)
	{
		l = -1;
		while (++l < 64)
		{
			data->map[i][j][k][l] = data->save[i][j][k][l];
			if (data->save[i][j][k][l] == 'z')
				data->map[i][j][k][l] = 1;
			if (data->save[i][j][k][l] >= 'a' \
				&& data->save[i][j][k][l] <= 'e')
				data->map[i][j][k][l] = data->save[i][j][k][l] - 95;
		}
	}
}

void				re_init_map(t_data *data)
{
	int				i;
	int				j;

	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < data->tier_ind)
			assign(data, i, j);
	}
}
