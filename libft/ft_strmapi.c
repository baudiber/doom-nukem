/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:40:05 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:40:05 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned i, char))
{
	int		i;
	char	*str;

	str = NULL;
	if (s)
	{
		str = ft_strnew(ft_strlen(s));
		if (!str)
			return (NULL);
		i = 0;
		while (s[i])
		{
			str[i] = f(i, s[i]);
			i++;
		}
	}
	return (str);
}
