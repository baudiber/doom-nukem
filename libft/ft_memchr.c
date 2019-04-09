/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:55 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:55 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	const unsigned char	*s2;

	s2 = s;
	i = 0;
	while (n--)
	{
		if (s2[i] == (unsigned char)c)
		{
			s2 = &s2[i];
			return ((void*)s2);
		}
		i++;
	}
	return (NULL);
}
