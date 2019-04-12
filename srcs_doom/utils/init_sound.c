/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sound.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:19:29 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/13 01:09:09 by roddavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		init_sound_2(t_env *e)
{
	if (!(e->sound.sound7 = Mix_LoadWAV("sound/DOOT-Nukem_get.wav")))
		exit_error(2, ERR_2);
	if (!(e->sound.sound8 = Mix_LoadWAV("sound/DOOT-Nukem_die.wav")))
		exit_error(2, ERR_2);
	if (!(e->sound.sound9 = Mix_LoadWAV("sound/DOOT-Nukem_win.wav")))
		exit_error(2, ERR_2);
	if (!(e->sound.sound10 = Mix_LoadWAV("sound/JUMP.wav")))
		exit_error(2, ERR_2);
	if (!(e->sound.sound11 = Mix_LoadWAV("sound/PAIN.wav")))
		exit_error(2, ERR_2);
}

void			init_sound(t_env *e)
{
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		exit_error(2, ERR_7);
	Mix_FreeMusic(e->sound.music);
	if (!(e->sound.music = Mix_LoadMUS("sound/DOOT-Nukem_loop_ambiance.wav")))
		exit_error(2, ERR_2);
	if (!(e->sound.sound1 = Mix_LoadWAV("sound/doot2000.wav")))
		exit_error(2, ERR_2);
	if (!(e->sound.sound2 = Mix_LoadWAV("sound/bruit_pas_gauche.wav")))
		exit_error(2, ERR_2);
	if (!(e->sound.sound3 = Mix_LoadWAV("sound/bruit_pas_droite.wav")))
		exit_error(2, ERR_2);
	if (!(e->sound.sound4 = Mix_LoadWAV("sound/Hello_Duke.wav")))
		exit_error(2, ERR_2);
	if (!(e->sound.sound5 = Mix_LoadWAV("sound/Pistol.wav")))
		exit_error(2, ERR_2);
	if (!(e->sound.sound6 = Mix_LoadWAV("sound/Shotgun.wav")))
		exit_error(2, ERR_2);
	init_sound_2(e);
	Mix_VolumeMusic(128 * 0.5);
	Mix_Volume(-1, 128 * 0.20);
}
