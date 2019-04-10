/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:00:05 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 15:00:15 by roddavid         ###   ########.fr       */
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
# define MAX_SIZE 64

# define NTEX 4
# define NWALL 3
# define NFLOOR 1
# define NSPRITE 0

# define VALID_CHAR "0123456789abcdez,- "
# define WALL_TEXT_MAX 9
# define FLOOR_TEXT_MAX 9
# define LIGHT_TEXT_MAX 9
# define EVENT_TEXT_MAX 9

# define DWALL 0
# define DFLOOR 1
# define DSPRITE 2
# define DLIGHT 3
# define DEVENT 4

# define ERR_BASE "Usage: ./doom-nukem map"
# define ERR_0 "Error: Can not open given file"
# define ERR_1 "Error: Malloc failed to allocate memory"
# define ERR_2 "Error: Ressource file not found"
# define ERR_3 "Error: Ressource can not be opened"
# define ERR_4 "Error: Map is not valid"
# define ERR_5 "Error: Please provide a spawn point for the player ('z')"
# define ERR_6 "Error: Please provide less than 100 sprite per map"
# define ERR_7 "Error: SDL initialisation encounter an error"
# define ERR_8 "Error: FOV value is wrong, must be between 60 - 130"
# define ERR_9 "Error: Grid size value is wrong must be: 64, 128, 256"

# include <unistd.h>
# include <sys/types.h>
//# include <sys/uio.h>
# include <stdbool.h>
# include <fcntl.h>
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
	unsigned int	*tex[9];
	SDL_Surface		*image[9];
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

extern int				main(int ac, char **av);
extern void				exit_error(int type);
extern void				init(t_e *e);
extern void				init_tab(t_e *e);
extern void				save(t_e *e);
extern void				engine_loop(t_e *e);
extern void				editor(t_e *e);
extern void				draw_panel_floor(t_e *e);
extern void				draw_panel_wall(t_e *e);
extern void				draw_panel_sprite(t_e *e);
extern void				draw_panel_light(t_e *e);
extern void				draw_panel_event(t_e *e);
extern void				draw_panel_tier(t_e *e);
extern void				draw_panel_grid_size(t_e *e);
extern void				draw_grid(t_e *e);
extern void				draw_texture_grid(t_e *e);
extern void				erase_texture_grid(t_e *e);
extern void				key_input(t_e *e);
extern void				realloc_tab(t_e *e);
extern unsigned int		*apply_texture(t_e *e);
extern void				redraw(t_e *e);
extern void				refresh_grid_var(t_e *e);
extern void				change_panel(t_e *e);
extern void				change_tier(t_e *e);
extern void				change_grid_size(t_e *e);
extern void				select_grid_block(t_e *e);
extern void				saving(t_e *e);
extern void				init_var_texture(t_e *e);
extern void				load_texture(t_e *e);
extern void				load_wall_texture(t_e *e);
extern void				load_floor_texture(t_e *e);
extern void				load_sprite_texture(t_e *e);
extern void				copy_texture(t_e *e);

#endif
extern
