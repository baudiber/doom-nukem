/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:40:11 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:40:11 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_freejoin(char *dst, char *src)
{
	char	*tmp;

	if (!dst)
		dst = ft_memalloc(sizeof(char));
	tmp = ft_strdup(dst);
	ft_strdel(&dst);
	if ((dst = ft_strjoin(tmp, src)) == NULL)
		return (NULL);
	ft_strdel(&tmp);
	return (dst);
}

static char			*ft_strcdup(const char *s, char c)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[size] && s[size] != c)
		size++;
	if (!(str = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*remains[42000];
	char			*tmp;
	int				ret;

	if ((ret = 1) && (fd < 0 || !line || BUFF_SIZE < 1))
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (!(tmp = NULL) && remains[fd] && remains[fd][0])
		tmp = ft_strdup(remains[fd]);
	while (!ft_strchr(tmp, '\n') && (ret = read(fd, &buf, BUFF_SIZE)) != 0)
		if (ret < 0 || (!(buf[ret] = 0)
		&& !(tmp = ft_freejoin(tmp, buf))))
			return (-1);
	if (remains[fd])
		free(remains[fd]);
	if (ret == 0 && !tmp && !(remains[fd] = NULL))
		return (0);
	remains[fd] = ft_strchr(tmp, '\n') ?
	ft_strdup(ft_strchr(tmp, '\n') + 1) : NULL;
	*line = ft_strcdup(tmp, '\n');
	free(tmp);
	return (1);
}
