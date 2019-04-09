/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:55 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:55 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int					i;
	const unsigned char	*ptr;
	unsigned char		*ptr2;

	ptr = src;
	ptr2 = dst;
	i = 0;
	while (n--)
	{
		ptr2[i] = ptr[i];
		i++;
	}
	return (ptr2);
}
