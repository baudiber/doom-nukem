/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:10:55 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/10 15:02:46 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void			stock_data(t_data *data, char *line)
{
	(data->scan) ? data->scan = ft_strjoinfree(data->scan, line, 1) : 0;
	(data->scan) ? data->scan = ft_strjoinfree(data->scan, "\n", 1) : 0;
	data->max_y += 1;
}

static bool			check_player(t_data *data)
{
	int				i;
	int				ret;

	i = 0;
	ret = 1;
	while (ret == 1 && data->scan[i])
	{
		if (data->scan[i] == 'z')
			ret = 0;
		i++;
	}
	return (ret == 0) ? true : false;
}

static bool			check_data(char *line, t_data *data)
{
	int				i;
	int				ret;

	i = 0;
	ret = 0;
	if (!line)
		ret = 1;
	if (ret == 0 && data->max_x == 0)
		data->max_x = (int)ft_countword(line, ' ');
	else if (!ft_strequ(line, "-\0")
			&& data->max_x != (int)ft_countword(line, ' '))
		ret = 1;
	if (data->max_y > (324) || data->max_x > 64)
		ret = 1;
	while (ret == 0 && line[i])
	{
		if (ft_strnchr(VALID_CHAR, line[i]) < 1)
			ret = 1;
		i++;
	}
	return (ret == 0) ? true : false;
}

static void			scan_data(t_data *data, int fd, char *line)
{
	int				rd;

	while ((rd = get_next_line(fd, &line)) > 0)
	{
		if (!line || (line && line[0] == '\0') \
				|| check_data(line, data) == false)
		{
			(line) ? ft_strdel(&line) : 0;
			parse_quit(data, 4, ERR_4);
		}
		stock_data(data, line);
		(line) ? ft_strdel(&line) : 0;
	}
	(line) ? ft_strdel(&line) : 0;
}

void				parse_scan(t_data *data, char *map)
{
	int				fd;

	((fd = open(map, O_DIRECTORY)) >= 0) ? parse_quit(data, 0, ERR_0) : 0;
	((fd = open(map, O_RDONLY)) < 0) ? parse_quit(data, 0, ERR_0) : 0;
	scan_data(data, fd, NULL);
	if (data->max_x < 1 || data->max_y < 1 || data->max_x > 64
			|| data->max_y > 324 || !data->scan)
		parse_quit(data, 4, ERR_4);
	if (!check_player(data))
		parse_quit(data, 5, ERR_5);
	if (!(data->tier = ft_strsplit(data->scan, '-')))
		parse_quit(data, 1, ERR_1);
	(ft_strnchr(data->scan, '-') > 4) ? parse_quit(data, 4, ERR_4) : 0;
	(data->scan) ? ft_strdel(&data->scan) : 0;
	close(fd);
}
