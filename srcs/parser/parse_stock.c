/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:45:18 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/19 15:54:35 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
