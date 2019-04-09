/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabintnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:40:09 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:40:10 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_tabintnew(size_t size)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	return (tab);
}
