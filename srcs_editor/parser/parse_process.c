/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:30:15 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/10 23:10:30 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

static bool			check_cell(char *cell)
{
	int				i;
	int				ret;
	int				digit;

	i = 0;
	ret = 0;
	digit = 0;
	while (ret == 0 && cell[i])
	{
		if (ft_isdigit(cell[i]) && digit == 0)
			digit = 1;
		if (!ft_isdigit(cell[i]) && digit != 0)
			ret = 1;
		i++;
	}
	return (ret == 0) ? true : false;
}

static bool			get_line(t_data *data, int y, char *line)
{
	int				x;
	int				ret;
	char			**tab;

	x = 0;
	ret = 0;
	tab = NULL;
	if (!(tab = ft_strsplit(line, ' ')))
		ret = 1;
	while (ret == 0 && tab[x])
	{
		if (!check_cell(tab[x]))
			ret = 1;
		parse_stock(y, x, data, tab[x]);
		x++;
	}
	(tab) ? ft_str_tabdel(&tab) : 0;
	return (ret == 0) ? true : false;
}

void				parse_process(t_data *data)
{
	int				y;

	y = 0;
	while (data->process[y])
	{
		if (!get_line(data, y, data->process[y]))
			parse_quit(data, 7);
		y++;
	}
	(data->process) ? ft_str_tabdel(&data->process) : 0;
}
