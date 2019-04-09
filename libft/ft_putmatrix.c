/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:58 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:58 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmatrix(char ***matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		ft_putnbr(i + 1);
		ft_putchar('\n');
		ft_puttab(matrix[i]);
		i++;
	}
}
