/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 23:14:37 by baudiber          #+#    #+#             */
/*   Updated: 2019/03/19 14:42:49 by clrichar         ###   ########.fr       */
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
