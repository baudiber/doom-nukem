/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:56 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:56 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	dest = dst;
	source = (unsigned char*)src;
	i = 0;
	if (src == dst)
		return (dst);
	if (source < dest)
	{
		while (len--)
			dest[len] = source[len];
	}
	else
	{
		while (len > i)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}
