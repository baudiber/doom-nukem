/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:45:18 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/29 17:45:09 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static int			is_cell(char *cell)
{
	bool			digit;

	digit = true;
	while (*cell)
	{
		if (!ft_isdigit(*cell))
			digit = false;
		cell++;
	}
	return (digit) ? 1 : 0;
}

void				parse_stock(int y, int x, t_data *data, char *cell)
{
	if (is_cell(cell) == 1)
		data->map[y][x] = ft_atoi(cell);
	else if (cell && cell[0])
		data->sprite[y][x] = cell[0];
}
