/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_degrees_radians.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:40:12 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/25 13:40:12 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			math_degrees_to_radians(double angle)
{
	return (angle * LM_PI / 180);
}

double			math_radians_to_degrees(double angle)
{
	return (angle * 180 / LM_PI);
}
