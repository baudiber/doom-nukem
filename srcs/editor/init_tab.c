/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:36:48 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/09 16:45:39 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_editor.h"

void	init_tab(t_e *e)
{
	int y;

	y = -1;
	while (++y <= TIER)
	{
		ft_memset(e->tab, 0, sizeof(e->tab));
	}
	y = -1;
	while (++y <= TIER)
	{
		ft_memset(e->tab[e->type], 0, sizeof(e->tab[e->type]));
	}
	y = -1;
	while (++y <= MAX_SIZE)
	{
		ft_memset(e->tab[e->type][e->tier], 0, sizeof(e->tab[e->type][e->tier]));
	}
}
