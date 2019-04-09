/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tabdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:40:00 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:40:00 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_str_tabdel(char ***as)
{
	int				i;

	if (as == NULL)
		return ;
	i = 0;
	while ((*as)[i])
	{
		if ((*as)[i])
			ft_strdel(&(*as)[i]);
		i++;
	}
	free((*as));
	(*as) = NULL;
}
