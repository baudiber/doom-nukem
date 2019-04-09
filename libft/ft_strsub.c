/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:40:08 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:40:08 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	str = NULL;
	if (s)
	{
		str = (char*)malloc(sizeof(char) * len + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (len--)
			str[i++] = s[start++];
		str[i] = '\0';
	}
	return (str);
}
