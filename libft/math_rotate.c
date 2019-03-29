/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:20:12 by clrichar          #+#    #+#             */
/*   Updated: 2019/03/20 15:28:11 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		rotate_line(t_line *line, float a)
{
	math_rotate_point(&line->a, a);
	math_rotate_point(&line->b, a);
}

void		math_rotate_point(t_point *p, float a)
{
	p->x = p->x * cosf(a) - p->y * sinf(a);
	p->y = p->x * sinf(a) + p->y * cosf(a);
}
