/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:47 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:47 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_convert(const char *str)
{
	int		j;
	int		i;
	int		k;

	j = ft_strlen(str);
	i = 0;
	k = 0;
	while (j--)
	{
		if (str[i] < '0' || str[i] > '9')
			return (k);
		k *= 10;
		k = k + str[i] - '0';
		i++;
	}
	return (k);
}

int				ft_atoi(const char *str)
{
	while (1)
	{
		if (str[0] == ' ' || (str[0] >= 9 && str[0] <= 13))
			str++;
		else if (str[0] == '-')
			return (-ft_convert(str + 1));
		else if (str[0] == '+')
			return (ft_convert(str + 1));
		else if (str[0] >= '0' && str[0] <= '9')
			return (ft_convert(str));
		else
			return (0);
	}
	return (0);
}
