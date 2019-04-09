/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freematrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:48 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:48 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freematrix(char ***tab)
{
	size_t	i;
	size_t	size;

	if (!tab)
		return ;
	size = ft_matrixlen(tab);
	i = 0;
	while (i < size + 1)
	{
		ft_freetab(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}
