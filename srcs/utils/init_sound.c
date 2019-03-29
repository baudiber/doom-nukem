/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sound.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:19:29 by roddavid          #+#    #+#             */
/*   Updated: 2019/03/29 17:45:09 by baudiber         ###   ########.fr       */
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

void		init_sound(t_env *e)
{
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		exit_error(2);
	//e->sound.music = NULL;
	//e->sound.sound1 = NULL;
	Mix_FreeMusic(e->sound.music);
	if (!(e->sound.music = Mix_LoadMUS("sound/MusicWolf.wav")))
		exit_error(2);
	if (!(e->sound.sound1 = Mix_LoadWAV("sound/doot2000.wav")))
		exit_error(2);
	if (!(e->sound.sound2 = Mix_LoadWAV("sound/bruit_pas_gauche.wav")))
		exit_error(2);
	if (!(e->sound.sound3 = Mix_LoadWAV("sound/bruit_pas_droite.wav")))
		exit_error(2);
	if (!(e->sound.sound4 = Mix_LoadWAV("sound/Hello_Duke.wav")))
		exit_error(2);
	if (!(e->sound.sound5 = Mix_LoadWAV("sound/Pistol.wav")))
		exit_error(2);
	if (!(e->sound.sound6 = Mix_LoadWAV("sound/Shotgun.wav")))
		exit_error(2);
	Mix_VolumeMusic(128 * 0.10);
	Mix_Volume(-1, 128 * 0.10);
}
