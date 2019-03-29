/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:37:40 by baudiber          #+#    #+#             */
/*   Updated: 2019/03/18 11:27:53 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int			ft_getstart(const char *s, char c, size_t n)
{
	unsigned int			i;
	size_t					j;

	i = 0;
	j = 0;
	n += 1;
	if (*(s + 0) != c && n == 1)
		return (0);
	else if (*(s + 0) != c)
		n--;
	i = 1;
	while (*(s + i) && j < n)
	{
		if (*(s + i) != c && *(s + (i - 1)) == c)
			j++;
		i++;
	}
	return (i - 1);
}

static size_t				ft_getend(char const *s, char c, size_t start)
{
	size_t					i;

	i = 0;
	while (*(s + (start + i)) != c && *(s + (start + i)) != '\0')
		i++;
	return (i);
}

char						**ft_strsplit(char const *s, char c)
{
	char					**ret;
	size_t					i;
	unsigned int			start;
	size_t					end;

	if (!s || !c)
		return (NULL);
	if (!(ret = (char**)malloc(sizeof(char*) * (ft_countword(s, c) + 1))))
		return (NULL);
	i = 0;
	while (i < ft_countword(s, c))
	{
		start = ft_getstart(s, c, i);
		end = ft_getend(s, c, start);
		ret[i] = ft_strsub(s, start, end);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
