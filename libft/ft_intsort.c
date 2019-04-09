/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:49 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:49 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intsort(int *tab, size_t size)
{
	size_t	a;
	size_t	b;
	int		tmp;

	if (!tab)
		return (NULL);
	a = 0;
	while (a < size - 1)
	{
		b = 1 + a;
		while (b < size)
		{
			if (tab[a] > tab[b])
			{
				tmp = tab[a];
				tab[a] = tab[b];
				tab[b] = tmp;
			}
			b++;
		}
		a++;
	}
	return (tab);
}
