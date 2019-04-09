/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:58 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:58 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putints(int *tab, size_t size)
{
	int		i;

	if (!tab)
		return ;
	i = 0;
	while (size--)
	{
		ft_putnbr(tab[i++]);
		write(1, "\n", 1);
	}
}
