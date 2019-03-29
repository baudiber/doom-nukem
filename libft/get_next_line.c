/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:25:40 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/19 14:40:58 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_strcut_free(char *s1, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s1[i] != c)
		i++;
	i++;
	tmp = ft_strdup(&(s1[i]));
	ft_strdel(&s1);
	return (tmp);
}

static int			ft_check(char **line, int fd)
{
	if (fd < 0 || fd >= 800 || line == NULL || (*line = NULL))
		return (-1);
	else
		return (1);
}

int					get_next_line(int fd, char **line)
{
	static char		*stc[800];
	char			buf[BUFF_SIZE + 1];
	int				ret;

	ret = ft_check(line, fd);
	while ((!stc[fd] || !ft_strchr(stc[fd], '\n'))
			&& (ret = (int)read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		stc[fd] = !stc[fd] ? ft_strdup(buf) : ft_strjoinfree(stc[fd], buf, 1);
	}
	if (ret <= 0 && stc[fd])
	{
		if (*stc[fd] == '\n' || *stc[fd] == '\0')
			return ((ret == -1) ? -1 : 0);
		*line = ft_strdup(stc[fd]);
		ft_strdel(&stc[fd]);
		return (1);
	}
	else if (ret <= 0 && !stc[fd])
		return ((ret == -1) ? -1 : 0);
	*line = ft_strsub(stc[fd], 0, (ft_strlen(stc[fd])
				- ft_strlen(ft_strchr(stc[fd], '\n'))));
	stc[fd] = ft_strcut_free(stc[fd], '\n');
	return (1);
}
