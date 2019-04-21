/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_multithreading.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:14:37 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/11 21:43:15 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		thread_nb(t_env *e)
{
	pthread_t	tid;
	int			i;

	tid = pthread_self();
	i = -1;
	while (++i < MAX_THREADS)
	{
		if (pthread_equal(e->tids[i], tid))
			break ;
	}
	return (i);
}

void	multithreaded_render(t_env *e)
{
	int			tid;

	tid = 0;
	while (tid < MAX_THREADS)
		pthread_create(&e->tids[tid++], NULL, raycaster_mt, e);
	tid = 0;
	while (tid < MAX_THREADS)
		pthread_join(e->tids[tid++], NULL);
}
