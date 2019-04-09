/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_sec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:40:01 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:40:01 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_sec(const char *s, int c)
{
	int		count;
	int		len;

	count = 0;
	if (!s)
		return (NULL);
	len = ft_strlen((char*)s) + 1;
	while (len--)
	{
		if (s[count] == (char)c)
			return ((char*)&s[count]);
		count++;
	}
	return (NULL);
}
