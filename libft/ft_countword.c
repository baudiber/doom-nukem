/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:48 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:48 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_countword(char const *s, char c)
{
	int					i;
	size_t				word;

	if (!s)
		return (0);
	i = 0;
	word = 0;
	if (s[0] != c)
		word++;
	while (s[i])
	{
		if (i >= 1 && (s[i] != c && s[i - 1] == c))
			word++;
		i++;
	}
	return (word);
}
