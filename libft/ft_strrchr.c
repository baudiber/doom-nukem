/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:40:07 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:40:07 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	int		len;
	char	*tmp;

	tmp = NULL;
	count = 0;
	len = ft_strlen((char*)s) + 1;
	while (len--)
	{
		if (s[count] == (char)c)
		{
			tmp = (char*)&s[count];
		}
		count++;
	}
	if (tmp)
		return (tmp);
	return (NULL);
}
