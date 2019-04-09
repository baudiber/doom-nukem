/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:40:04 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:40:04 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	str = NULL;
	if (s1 && s2)
	{
		len = (ft_strlen(s1) + ft_strlen(s2));
		str = ft_strnew(len + 1);
		if (!str)
			return (NULL);
		str = ft_strcat(str, s1);
		str = ft_strcat(str, s2);
		str[len + 1] = '\0';
	}
	return (str);
}
