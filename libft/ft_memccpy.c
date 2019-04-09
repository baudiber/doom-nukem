/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:54 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:55 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int					i;
	const unsigned char	*srctmp;
	unsigned char		*dsttmp;

	i = 0;
	srctmp = src;
	dsttmp = dst;
	while (n--)
	{
		dsttmp[i] = srctmp[i];
		if (srctmp[i] == (unsigned char)c)
			return (dsttmp = &dsttmp[i + 1]);
		i++;
	}
	return (NULL);
}
