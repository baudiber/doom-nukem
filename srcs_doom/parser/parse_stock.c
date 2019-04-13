/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:45:18 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/14 00:07:31 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static bool			is_over_max(int y, int x, t_data *data)
{
	if (data->map[DWALL][data->tier_ind][y][x] > WALL_TEXT_MAX)
		data->map[DWALL][data->tier_ind][y][x] = WALL_TEXT_MAX;
	if (data->map[DFLOOR][data->tier_ind][y][x] > FLOOR_TEXT_MAX)
		data->map[DFLOOR][data->tier_ind][y][x] = FLOOR_TEXT_MAX;
	if (data->map[DSPRITE][data->tier_ind][y][x] > 255)
		return (false);
	if (data->map[DLIGHT][data->tier_ind][y][x] > LIGHT_TEXT_MAX)
		data->map[DLIGHT][data->tier_ind][y][x] = LIGHT_TEXT_MAX;
	if (data->map[DEVENT][data->tier_ind][y][x] > EVENT_TEXT_MAX)
		return (false);
	return (true);
}

static bool			is_full_ascii(char *cell)
{
	bool			ascii;

	ascii = true;
	while (ascii == true && *cell)
	{
		if (ft_isdigit(*cell))
			ascii = false;
		cell++;
	}
	return (ascii);
}

static bool			is_full_digit(char *cell)
{
	bool			digit;

	digit = true;
	while (digit == true && *cell)
	{
		if (!ft_isdigit(*cell))
			digit = false;
		cell++;
	}
	return (digit);
}

static bool			check_stock(t_data *data)
{
	int				ret;

	ret = 0;
	if (!data->cell || !data->cell[0] || !data->cell[1])
		ret = 1;
	if (ret == 0 && (!is_full_digit(data->cell[0]) \
			&& !is_full_ascii(data->cell[0])))
		ret = 1;
	if (ret == 0 && !is_full_digit(data->cell[1]))
		ret = 1;
	return (ret == 0) ? true : false;
}

void				parse_stock(int y, int x, t_data *data, char *cell)
{
	if (!(data->cell = ft_strsplit(cell, ',')) || !cell)
	{
		(cell) ? ft_strdel(&cell) : 0;
		parse_quit(data, 1, ERR_1);
	}
	if (!check_stock(data))
	{
		(cell) ? ft_strdel(&cell) : 0;
		parse_quit(data, 4, ERR_4);
	}
	if (data->cell && is_full_digit(data->cell[0]))
		data->map[DWALL][data->tier_ind][y]\
		[x] = (uint32_t)ft_atoi(data->cell[0]);
	else
	{
		data->map[DWALL][data->tier_ind][y][x] = 0;
		data->map[DSPRITE][data->tier_ind][y][x] = (uint32_t)data->cell[0][0];
	}
	data->map[DFLOOR][data->tier_ind][y][x] = (uint32_t)ft_atoi(data->cell[1]);
	data->map[DLIGHT][data->tier_ind][y][x] = (uint32_t)ft_atoi(data->cell[2]);
	data->map[DEVENT][data->tier_ind][y][x] = (uint32_t)ft_atoi(data->cell[3]);
	(data->cell) ? ft_str_tabdel(&data->cell) : 0;
	if (!is_over_max(y, x, data))
		parse_quit(data, 4, ERR_4);
}
