/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:33:45 by clrichar          #+#    #+#             */
/*   Updated: 2018/01/27 17:33:45 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strnchr(const char *s, int c)
{
	int			i;

	i = 0;
	while (*s)
	{
		if (*s == (char)c)
			i++;
		s++;
	}
	return (i);
}
