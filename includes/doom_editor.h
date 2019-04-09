/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:43:06 by clrichar          #+#    #+#             */
/*   Updated: 2019/04/09 18:09:53 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOOM_EDITOR_H

# define DOOM_EDITOR_H
# define WIN_W 1920
# define WIN_H 1280
# define MARGIN 40
# define PANEL 440
# define TIER 5
# define TEX_SIZE 256
# define MAX_SIZE 128

# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <pthread.h>
# include "SDL.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"
//# include "SDL_image.h"
# include "libft.h"

typedef struct		s_draw
{
	SDL_Rect		position;
	SDL_Surface		*text;
	TTF_Font		*font;
	SDL_Color		white;
}					t_draw;

typedef struct		s_window
{
	SDL_Window		*win;
	SDL_Surface		*screen;
	SDL_Event		event;
	SDL_Renderer	*renderer;
}					t_window;

typedef struct		s_grid
{
	int				x;
	int				y;
	double			padx;
	double			pady;
	int				countpadx;
	int				countpady;
	int				mouseposgridx;
	int				mouseposgridy;
	int				mouseposx;
	int				mouseposy;
	SDL_Rect		grid_rect;
}					t_grid;

typedef struct		s_texture
{
	//SIMPLE COLOR FOR NOW
	float			ratiox;
	float			ratioy;
	float			x;
	float			y;
	int				texture;
	unsigned int	*tex[8];
	SDL_Surface		*image[8];
}					t_texture;

typedef	struct		s_e
{
	int				wellcome_screen;
	Uint32			*buff;
	t_window		window;
	t_draw			draw[4];
	t_grid			grid;
	t_texture		texture;
	int				tier;
	int				type;
	unsigned int	tab[5][TIER][MAX_SIZE][MAX_SIZE];
	int				dif_size;
	void			(*f[5])(struct s_e *e);
	int				panel_index;
	int				argc;
	char			**argv;
}					t_e;

int					main(int ac, char **av);
void				exit_error(int type);
void				init(t_e *e);
void				init_tab(t_e *e);
void				save(t_e *e);
void				engine_loop(t_e *e);
void				editor(t_e *e);
void				draw_panel_floor(t_e *e);
void				draw_panel_wall(t_e *e);
void				draw_panel_sprite(t_e *e);
void				draw_panel_light(t_e *e);
void				draw_panel_event(t_e *e);
void				draw_panel_tier(t_e *e);
void				draw_panel_grid_size(t_e *e);
void				draw_grid(t_e *e);
void				draw_texture_grid(t_e *e);
void				erase_texture_grid(t_e *e);
void				key_input(t_e *e);
void				realloc_tab(t_e *e);
unsigned int		*apply_texture(t_e *e);
void				redraw(t_e *e);
void				refresh_grid_var(t_e *e);
void				change_panel(t_e *e);
void				change_tier(t_e *e);
void				change_grid_size(t_e *e);
void				select_grid_block(t_e *e);
void				saving(t_e *e);
void				init_var_texture(t_e *e);
void				load_texture(t_e *e);
void				load_wall_texture(t_e *e);
void				load_floor_texture(t_e *e);
void				load_sprite_texture(t_e *e);
void				copy_texture(t_e *e);

#endif
