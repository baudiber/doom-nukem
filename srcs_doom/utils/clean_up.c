/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:35:50 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/13 01:07:02 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		clean_up(t_env *e)
{
	Mix_FreeChunk(e->sound.sound1);
	Mix_FreeChunk(e->sound.sound2);
	Mix_FreeChunk(e->sound.sound3);
	Mix_FreeChunk(e->sound.sound4);
	Mix_FreeChunk(e->sound.sound5);
	Mix_FreeChunk(e->sound.sound6);
	Mix_FreeMusic(e->sound.music);
	Mix_CloseAudio();
	SDL_DestroyWindow(e->win);
	SDL_Quit();
}
