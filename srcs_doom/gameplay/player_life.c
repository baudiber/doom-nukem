/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:24:42 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/12 18:55:45 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		init_chr_life(t_env *e)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	while (++i <= 101)
	{
		tmp = ft_itoa(i);
		ft_strncpy(e->player.hp_str[i], tmp, 4);
		tmp ? ft_strdel(&tmp) : 0;
	}
}

void		draw_life(t_env *e)
{
	int i = -1;
	while (++i <= 101)
	{
		ft_putendl(e->player.hp_str[e->player.hp]);
//		ft_putendl(e->player.hp_str[i]);
	}
}

