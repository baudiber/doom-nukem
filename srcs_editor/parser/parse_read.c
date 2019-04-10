/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:10:55 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/29 17:45:09 by baudiber         ###   ########.fr       */
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
	else if (data->max_x != (int)ft_countword(line, ' '))
		ret = 1;
	if (data->max_y > 128 || data->max_x > 128)
		ret = 1;
	while (ret == 0 && line[i])
	{
		if (ft_strnchr(VALID_CHAR, line[i]) < 1)
			ret = 1;
		i++;
	}
	return (ret == 0) ? true : false;
}

static void			get_data(t_data *data, int fd, char *line)
{
	int				rd;

	while ((rd = get_next_line(fd, &line)) > 0)
	{
		if (!line || (line && line[0] == '\0') \
				|| check_data(line, data) == false)
		{
			(line) ? ft_strdel(&line) : 0;
			parse_quit(data, 7);
		}
		stock_data(data, line);
		(line) ? ft_strdel(&line) : 0;
	}
	(line) ? ft_strdel(&line) : 0;
}

void				parse_read(t_data *data, char *map)
{
	int				fd;

	parse_init(data);
	if ((fd = open(map, O_DIRECTORY)) >= 0)
		parse_quit(data, 7);
	if ((fd = open(map, O_RDONLY)) < 0)
		parse_quit(data, 7);
	get_data(data, fd, NULL);
	if (data->max_x < 1 || data->max_y < 1 || data->max_x > 128
			|| data->max_y > 128 || !data->scan)
		parse_quit(data, 7);
	if (!check_player(data))
		parse_quit(data, 6);
	if (!(data->process = ft_strsplit(data->scan, '\n')))
		parse_quit(data, 1);
	(data->scan) ? ft_strdel(&data->scan) : 0;
	close(fd);
	parse_process(data);
	parse_pos(data);
}
