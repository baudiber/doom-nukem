/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <baudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:06:00 by baudiber          #+#    #+#             */
/*   Updated: 2019/03/31 17:34:39 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H

# define WOLF3D_H
# define FOV 60
# define WIN_W 800
# define WIN_H 600
# define DEBUG 0
# define MAX_FPS 600
# define MAX_MAPSIZE 128
# define UI_Y2 300
# define GRID_SIZE_STR "256"
# define TILE_SIZE 256
# define WALL_HEIGHT 256
# define MAX_THREADS 8
# define MAX_VISIBLE_SPRITE 30
# define VALID_CHAR "0123456789abcz "

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include "SDL.h"
# include "SDL_ttf.h"
# include "SDL_mixer.h"
# include "libft.h"

typedef struct		s_files
{
	unsigned int	*wall[4];
	unsigned int	*sprite[9];
	unsigned int	*floor[2];
	unsigned int	*ui;
	unsigned int	*face[5];
	unsigned int	*inv[3];
	unsigned int	*pistol[6];
	unsigned int	*shotgun[6];
	SDL_Surface		*image[35];
	SDL_Surface		*skybox;
	SDL_Surface     *ui_surf;
}					t_files;

typedef struct		s_data
{
	int				pos_y;
	int				pos_x;
	int				max_x;
	int				max_y;
	char			*scan;
	char			**process;
	int				map[2][2][128][128];
	char			sprite[128][128];
}					t_data;

typedef struct		s_draw
{
	char			*str;
	SDL_Rect		sky_rect;
	SDL_Rect		sky_rect2;
	float			skybox_x;
	int				skybox_y;
	TTF_Font		*font;
	SDL_Surface		*fps_surface;
	SDL_Color		white;
	Uint32			color;
}					t_draw;

typedef struct		s_menu
{
	int				i_img;
	int				check;
	int				check_options;
	int				mute;
	int				save_img;
	int				save_img2;
	SDL_Surface		*image[18];
}					t_menu;

typedef struct		s_minimap
{
	int				i;
	int				j;
	int				i2;
	int				j2;
	int				x;
	int				y;
	double			pady;
	double			padx;
}					t_minimap;

typedef struct		s_sound
{
	Mix_Music		*music;
	Mix_Chunk		*sound1;
	Mix_Chunk		*sound2;
	Mix_Chunk		*sound3;
	Mix_Chunk		*sound4;
	Mix_Chunk		*sound5;
	Mix_Chunk		*sound6;
}					t_sound;

typedef struct		s_time
{
	double			last_time;
	double			new_time;
	double			frame_time;
	double			max_time;
	double			delta_time;
}					t_time;

typedef struct		s_sprite
{
	int				tex;
	bool			visible;
	float			dead;
	int				x;
	int				y;
	double			dist;
	int				height;
	int				screen_x;
}					t_sprite;

typedef struct		s_player
{
	t_point			pos;
	t_point_int		map;
	int				plane_dist;
	int				height;
	int				angle;
	int				speed;
	bool			moving;
	int				pace;
}					t_player;

typedef struct		s_sprite_calculation
{
	int				screen_x;
	int				height;
	t_point_int		map;
	t_point			r;
	t_point			t;
}					t_sprite_calculation;

typedef struct		s_sprite_draw
{
	Uint32			color;
	int				offsave;
	t_point_int		texture;
	t_point_int		start;
	t_point_int		end;
	t_point_int		offset;
	double			ratio;
}					t_sprite_draw;

typedef struct		s_wall
{
	int				tex;
	int				top;
	int				bottom;
	int				texture_x;
	int				texture_y;
	double			dist;
	double			height;
	double			color;
}					t_wall;

typedef struct		s_vert
{
	int				x;
	int				next_x;
	double			dist;
	double			y;
	double			next_y;
	t_point_int		map;
}					t_vert;

typedef struct		s_hor
{
	double			dist;
	int				y;
	int				next_y;
	double			x;
	double			next_x;
	t_point_int		map;
}					t_hor;

typedef struct		s_ray
{
	t_vert			vert;
	t_hor			hor;
	int				angle;
	int				layer;
}					t_ray;

typedef struct		s_floor
{
	int				x;
	int				y;
	t_point_int		map;
	double			dist;
}					t_floor;

typedef struct		s_angles
{
	int				a_2;
	int				a_5;
	int				a_half_fov;
	int				a_40;
	int				a_90;
	int				a_140;
	int				a_180;
	int				a_270;
	int				a_360;
}					t_angles;

typedef struct		s_draw_scaled
{
	float			x_start;
	float			y_start;
	float			x_end;
	float			y_end;
	int				w;
	unsigned int	**buffer;
	double			x_ratio;
	double			y_ratio;
	Uint32			index;
}					t_draw_scaled;

typedef struct		s_ui
{
	int				weapon;
	int				weapon_firing;
	int				weapon_fired;
	int				ui_size;
	int				pistol_ystart;
	int				shotgun_ystart;
}					t_ui;

typedef struct		s_env
{
	Uint32			*buff;
	SDL_Window		*win;
	SDL_Surface		*screen;
	SDL_Event		event;
	const Uint8		*state;
	pthread_t		tids[MAX_THREADS];
	t_ray			ray[MAX_THREADS];
	t_wall			wall[MAX_THREADS];
	t_floor			floor[MAX_THREADS];
	t_angles		angle;
	double			sin_table[(int)(360 * ((double)WIN_W / FOV) + 1)];
	double			i_sin_table[(int)(360 * ((double)WIN_W / FOV) + 1)];
	double			cos_table[(int)(360 * ((double)WIN_W / FOV) + 1)];
	double			i_cos_table[(int)(360 * ((double)WIN_W / FOV) + 1)];
	double			tan_table[(int)(360 * ((double)WIN_W / FOV) + 1)];
	double			i_tan_table[(int)(360 * ((double)WIN_W / FOV) + 1)];
	double			x_step_table[(int)(360 * ((double)WIN_W / FOV) + 1)];
	double			y_step_table[(int)(360 * ((double)WIN_W / FOV) + 1)];
	double			fisheye_table[WIN_W];
	double			i_fisheye_table[WIN_W];
	t_menu			menu;
	t_player		player;
	t_data			data;
	t_sprite		sprites[100];
	t_files			files;
	t_sound			sound;
	t_minimap		minimap;
	t_draw_scaled	face_info;
	t_draw_scaled	inv_info;
	t_draw_scaled	pistol_info;
	t_draw_scaled	shotgun_info;
	t_ui			ui;
	int				sprite_nb;
	bool			spotvis[MAX_MAPSIZE][MAX_MAPSIZE];
	double			wall_heights[WIN_W];
	int				horizon;
	int				tile_shift;
	int				thread_col_size;
	int				render_limit;
	int				max_speed;
	bool			barrel_tick;
	t_point			prev_mouse;
	t_point			mouse;
	t_draw			draw;
	t_time			time;
}					t_env;

extern int			main(int argc, char **argv);
extern void			m_parser(int fd, t_env *e);
extern void			load_textures(t_env *e);
extern void			load_textures_menu(t_env *e);
extern void			engine_loop(t_env *e);
extern void			init_rects_and_font(t_env *e);
extern void			drawing(t_env *e, int x);
extern void			init_sdl(t_env *e);
extern void			init_player(t_env *e);
extern void			init_sound(t_env *e);
extern void			init_vars(t_env *e);
extern void			exit_error(int type);

extern void			parse_init(t_data *data);
extern void			parse_read(t_data *data, char *map);
extern void			parse_process(t_data *data);
extern void			parse_stock(int y, int x, t_data *data, char *cell);
extern void			parse_pos(t_data *data);
extern void			parse_sprite(t_env *e);
extern void			parse_quit(t_data *data, int type);
extern void			exit_error(int type);

extern void			load_screen(t_env *e);
extern void			load_screen_2(t_env *e, int check, SDL_Event ev);
extern void			ft_menu(t_env *e);
extern void			ft_menu_2(t_env *e, SDL_Event ev);
extern void			ft_menu_2_2(t_env *e, SDL_Event ev);
extern void			ft_menu_3(t_env *e, SDL_Event ev, int *x, int *y);
extern void			mouse_menu_2(t_env *e, int y, SDL_Event ev);
extern void			ft_menu_options(t_env *e);
extern void			ft_menu_options_2(t_env *e, SDL_Event ev, int x, int y);
extern void			refresh_gif(t_env *e, int i);
extern void			ft_slider(t_env *e, int x, int y, SDL_Event ev);
extern void			gif_load_screen(t_env *e);
extern void			clean_up(t_env *e);

extern void			get_vertical_hit(t_env *e, int tid);
extern void			get_horizontal_hit(t_env *e, int tid);
extern int			ray_is_in_the_map(int x, int y, t_env *e);
extern void			angle_overflow(int *angle, t_env *e);
extern double		angle_to_rad(int angle, t_env *e);
extern void			get_wall_height(t_env *e, int column, int tid);
extern void			draw_wall(t_env *e, int column, int tid);
extern void			floor_casting(t_env *e, int	column, int tid);
extern void			moving_rects(t_env *e);
extern void			display_skybox(t_env *e);
extern void			multithreaded_render(t_env *e);
extern void			*raycaster_mt(void *arg);
extern int			thread_nb(t_env *e);
extern void			draw_sprites(t_env *e);
extern void			move_player(t_env *e);
extern void			get_delta(int angle, t_env *e, t_point *new_pos);
extern void			walk_forward_and_backward(t_env *e, t_point *new_pos, int *tmpangle);
extern void			strafe(t_env *e, t_point *new_pos, int *tmpangle);
extern void			strafe_backward(t_env *e, t_point *new_pos, int *tmpangle);
extern void			strafe_forward(t_env *e, t_point *new_pos, int *tmpangle);
extern void			crouch_and_jump(t_env *e);
extern void			mouse_aim(t_env *e);
extern bool			check_walls(t_env *e, int height, int *offset, int x);
extern void			sprite_rotation(t_env *e, t_sprite_calculation *calc, int sprite);
extern void			get_screen_coord(t_env *e, t_sprite_draw *draw, t_sprite *sprite);
extern void			clip_end(int *end, int y);
extern void			clip_start(int *start, int *offset);
extern void			mouse_aim_x(t_env *e);
extern void			mouse_aim_y(t_env *e);
extern void			pick_up_obj(t_env *e, int nb);
extern void			minimap(t_env *e);
extern void			draw_player_small(t_env *e);
extern void			draw_player_big(t_env *e);
extern void			draw_map_small(t_env *e);
extern void			draw_map_big(t_env *e);
extern void			init_struct_minimap(t_env *e);
extern void			weapon_switch(t_env *e);
extern void			weapon_fire(t_env *e);

extern void			draw_ui_base(t_env *e);
extern void			draw_ui(t_env *e);
extern void			animations(t_env *e);
extern void			init_ui_structs(t_env *e);
extern void			fake_parse(t_env *e);
extern void			draw_ceilings(t_env *e, int x, int tid);
#endif
