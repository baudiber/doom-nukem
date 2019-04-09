/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:40:10 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:40:10 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabnew(size_t size)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * size + 1);
	if (!tab)
		return (NULL);
	tab[size] = NULL;
	return (tab);
}
