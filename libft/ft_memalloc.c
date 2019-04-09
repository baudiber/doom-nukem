/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:54 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:54 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = (void*)malloc(sizeof(void*) * size + 1);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
