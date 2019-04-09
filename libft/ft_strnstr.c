/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:40:07 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:40:07 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;

	if (!(*needle))
		return ((char*)haystack);
	if (len == 0)
		return (NULL);
	i = (int)ft_strlen(needle);
	while (len)
	{
		if (!(*haystack))
			return (NULL);
		if ((ft_strncmp((char*)haystack, (char*)needle, (size_t)i) == 0)
				&& ((int)len + 1 - i) > 0)
			return ((char*)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
