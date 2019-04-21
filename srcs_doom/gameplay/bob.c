/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bob.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 03:30:11 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/13 03:32:07 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			bob(t_env *e)
{
	if (e->player.moving)
	{
		e->pistol_info.y_start = e->ui.pistol_ystart \
			+ round(sin(math_degrees_to_radians(e->player.pace)) * 30);
		e->shotgun_info.y_start = e->ui.shotgun_ystart \
			+ round(sin(math_degrees_to_radians(e->player.pace)) * 20);
	}
}
