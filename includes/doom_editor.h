/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roddavid <roddavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:00:05 by roddavid          #+#    #+#             */
/*   Updated: 2019/04/10 20:33:40 by clrichar         ###   ########.fr       */
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

# define NTEX 8
# define NWALL 3
# define NFLOOR 2
# define NSPRITE 2
# define NLIGHT 1
# define NEVENT 0

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

typedef struct		s_data
{
	int				tier_ind;
	int				tier_size;
	int				pos_y;
	int				pos_x;
	int				pos_z;
	int				max_x;
	int				max_y;
	char			*scan;
	char			**tier;
	char			**stage;
	char			**cell;
	unsigned int	map[5][5][64][64];
}					t_data;

typedef struct		s_sprite
{
	int				tex;
	bool			visible;
	double			dead;
	int				x;
	int				y;
	int				z;
	int				floor;
	double			dist;
	int				height;
	int				screen_x;
}					t_sprite;

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
	unsigned int	*tex[13];
	SDL_Surface		*image[13];
}					t_texture;

typedef	struct		s_env
{
	int				wellcome_screen;
	int				parsed;
	Uint32			*buff;
	t_window		window;
	t_draw			draw[4];
	t_grid			grid;
	t_texture		texture;
	t_data			data;
	t_sprite		sprites[100];
	int				tier;
	int				type;
	unsigned int	tab[5][TIER][MAX_SIZE][MAX_SIZE];
	int				dif_size;
	void			(*f[5])(struct s_env *e);
	int				panel_index;
	int				argc;
	int				sprite_nb;
	char			**argv;
}					t_env;

extern int				main(int ac, char **av);
extern void				init(t_env *e);
extern void				init_from_parser(t_env *e);
extern void				init_tab(t_env *e);
extern void				save(t_env *e);
extern void				engine_loop(t_env *e);
extern void				editor(t_env *e);
extern void				draw_panel_floor(t_env *e);
extern void				draw_panel_wall(t_env *e);
extern void				draw_panel_sprite(t_env *e);
extern void				draw_panel_light(t_env *e);
extern void				draw_panel_event(t_env *e);
extern void				draw_panel_tier(t_env *e);
extern void				draw_panel_grid_size(t_env *e);
extern void				draw_grid(t_env *e);
extern void				draw_texture_grid(t_env *e);
extern void				erase_texture_grid(t_env *e);
extern void				key_input(t_env *e);
extern unsigned int		*apply_texture(t_env *e);
extern void				redraw(t_env *e);
extern void				refresh_grid_var(t_env *e);
extern void				change_panel(t_env *e);
extern void				change_tier(t_env *e);
extern void				change_grid_size(t_env *e);
extern void				select_grid_block(t_env *e);
extern void				saving(t_env *e);
extern void				init_var_texture(t_env *e);
extern void				load_texture(t_env *e);
extern void				load_wall_texture(t_env *e);
extern void				load_floor_texture(t_env *e);
extern void				load_sprite_texture(t_env *e);
extern void				load_light_texture(t_env *e);
extern void				copy_texture(t_env *e);
extern void				copy_from_parser(t_env *e);

extern void				parse_init(t_data *data);
extern void				parse_start(t_data *data, char *map);
extern void				parse_scan(t_data *data, char *map);
extern void				parse_tier(t_data *data);
extern void				parse_stage(t_data *data);
extern void				parse_stock(int y, int x, t_data *data, char *cell);
extern void				parse_pos(t_data *data);
extern void				parse_sprite(t_env *e);
extern void				parse_quit(t_data *data, int type, char *msg);
extern void				exit_error(int type, char *msg);

#endif
extern
