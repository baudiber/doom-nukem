/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:40:04 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:40:04 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoinfree(const char *s1, const char *s2, int index)
{
	char		*dest;

	if (!(s1 && s2))
		return (NULL);
	else if (!(dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	if (s1)
		dest = ft_strcat(dest, s1);
	if (s2)
		dest = ft_strcat(dest, s2);
	if (index == 1)
		free((void *)s1);
	else if (index == 2)
		free((void *)s2);
	else if (index == 3)
	{
		free((void *)s1);
		free((void *)s2);
	}
	return (dest);
}
