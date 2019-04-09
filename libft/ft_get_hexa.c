/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:39:49 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:39:49 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_get_hexa(char *str)
{
	unsigned int	hexa;

	hexa = ft_strtoui(str, "0123456789ABCDEF");
	return (hexa);
}
