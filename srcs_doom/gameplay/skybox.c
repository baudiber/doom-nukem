/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:56:01 by baudiber          #+#    #+#             */
/*   Updated: 2019/04/13 16:32:30 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	crop_skybox(t_env *e)
{
	printf("ystart %f yend %f\n", e->skybox_info.y_start, e->skybox_info.y_end);
	if (e->skybox_info.y_start < 0)
	{
		e->skybox_info.y_offset = -(e->skybox_info.y_start);
		e->skybox_info.y_start = 0;
	}
	else
		e->skybox_info.y_offset = 0;
	if (e->skybox_info.y_end >= e->render_limit)
		e->skybox_info.y_end = e->render_limit;
}
