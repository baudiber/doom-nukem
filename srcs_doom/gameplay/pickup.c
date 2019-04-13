/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 03:35:22 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/14 00:00:07 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		do_pickup_2(t_env *e, int nb)
{
	if (e->sprites[nb].tex == 14 && e->player.hp < 100)
	{
		e->player.hp += 30;
		e->player.hp = (e->player.hp > 100) ? 100 : e->player.hp;
		e->sprites[nb].visible = false;
	}
}

static void		do_pickup_1(t_env *e, int nb)
{
	if (e->sprites[nb].tex == 4)
	{
		Mix_PlayChannel(-1, e->sound.sound4, 0);
		e->inv_info.index = 2;
		e->sprites[nb].visible = false;
		e->ui.weapon = (e->ui.weapon == 0) ? 2 : e->ui.weapon;
	}
	else if (e->sprites[nb].tex == 13 && e->ui.trumpet)
	{
		Mix_PlayChannel(-1, e->sound.sound9, 0);
		e->player.win = true;
		end_game(e, "YOU WIN");
	}
	else if (e->sprites[nb].tex == 7)
	{
		Mix_PlayChannel(-1, e->sound.sound7, 0);
		e->sprites[nb].visible = false;
		e->ui.trumpet = true;
	}
	else
		do_pickup_2(e, nb);
}

void			pick_up_obj(t_env *e, int nb)
{
	int		range;

	if ((e->sprites[nb].tex != 4 && e->sprites[nb].tex != 7 \
			&& e->sprites[nb].tex != 13 && e->sprites[nb].tex != 14) \
			|| !e->sprites[nb].visible)
		return ;
	range = TILE_SIZE * 0.75;
	if ((fabs(e->sprites[nb].x - e->player.pos.x) < range) \
		&& (fabs(e->sprites[nb].y - e->player.pos.y) < range) \
		&& e->sprites[nb].floor == e->player.floor)
		do_pickup_1(e, nb);
}
