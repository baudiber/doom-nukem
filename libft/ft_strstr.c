/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:40:08 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:40:08 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	if (!(*needle))
		return ((char*)haystack);
	i = ft_strlen(needle);
	j = 0;
	while (j < (int)ft_strlen(haystack))
	{
		if (ft_strncmp((char*)&haystack[j], (char*)needle, i) == 0)
			return ((char*)&haystack[j]);
		j++;
	}
	return (NULL);
}
