/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:40:09 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:40:09 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	start;
	char	*str;

	str = NULL;
	if (s)
	{
		len = ft_strlen(s);
		start = 0;
		while ((s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
				&& start < len)
			start++;
		if (start == len)
			return (ft_strnew(0));
		len--;
		while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && s[len])
			len--;
		if (!(str = ft_strnew(len - start)))
			return (NULL);
		str = ft_strsub(s, (unsigned int)start, len - start + 1);
	}
	return (str);
}
