/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fly_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 03:13:58 by gagonzal          #+#    #+#             */
/*   Updated: 2019/04/13 03:23:19 by gagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			fly_mode(t_env *e)
{
	int			val;

	val = MAX_FLOORS * 2 * TILE_SIZE;
	if ((e->state[SDL_SCANCODE_LCTRL] || e->state[SDL_SCANCODE_C]))
	{
		if (e->player.height > 10)
			e->player.height -= 30;
	}
	else if (e->state[SDL_SCANCODE_SPACE])
	{
		if (e->player.height <= val)
			e->player.height += 30;
	}
}
