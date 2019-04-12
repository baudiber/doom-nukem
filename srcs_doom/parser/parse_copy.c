/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:04:53 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/12 02:10:42 by clrichar         ###   ########.fr       */
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
			data->save[i][j][k][l] = data->map[i][j][k][l];
			if (data->map[i][j][k][l] == 'z')
				data->save[i][j][k][l] = 1;
			if (data->map[i][j][k][l] >= 'a' \
					&& data->map[i][j][k][l] <= 'e')
				data->save[i][j][k][l] = data->map[i][j][k][l] - 95;
		}
	}
}

void				parse_copy(t_data *data)
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
