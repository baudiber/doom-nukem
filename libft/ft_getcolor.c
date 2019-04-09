/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:49 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:49 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_getcolor(char *str)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	if ((tmp = ft_strchr(str, ',')))
	{
		tmp++;
		i = ft_get_hexa(tmp);
	}
	return (i);
}
