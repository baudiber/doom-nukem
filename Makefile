# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clrichar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 15:08:30 by clrichar          #+#    #+#              #
#    Updated: 2019/04/12 02:36:08 by clrichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=				DOOM-NUKEM
NAMEA				:=				doom-nukem
NAMEB				:=				doom-editor

#==============================================================================#
#------------------------------------------------------------------------------#
#                               DIRECTORIES                                    #

INC_DIR				:=			./includes
SRC_DIRA			:=			./srcs_doom
SRC_DIRB			:=			./srcs_editor
OBJ_DIRA			:=			./objs_doom
OBJ_DIRB			:=			./objs_editor
LIB_DIR				:=			./libft
LIBFT				:=			./libft/libft.a

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  FILES                                       #

SRCA			=				main.c										\
								main_loop.c									\
								engine/engine_dda.c							\
								engine/engine_draw_walls.c					\
								engine/engine_floor_casting.c				\
								engine/engine_multithreading.c				\
								engine/engine_raycasting.c					\
								engine/engine_sprites.c						\
								engine/engine_sprites_utils.c				\
								engine/engine_draw_ceiling.c				\
								gameplay/player_movement.c					\
								gameplay/mouse_aim.c						\
								gameplay/move_player.c						\
								gameplay/ui.c								\
								gameplay/sprite_interaction.c				\
								gameplay/minimap.c							\
								gameplay/minimap_drawplayer.c				\
								gameplay/minimap_drawmap.c					\
								gameplay/weapon_switch.c					\
								gameplay/weapon_fire.c						\
								gameplay/player_events.c					\
								parser/parse_scan.c							\
								parser/parse_stage.c						\
								parser/parse_tier.c							\
								parser/parse_stock.c						\
								parser/parse_copy.c							\
								parser/parse_sprite.c						\
								parser/parse_utils.c						\
								menu/menu.c									\
								menu/menu_2.c								\
								menu/menu_options.c							\
								menu/menu_options_slider.c					\
								utils/init.c								\
								utils/init_vars.c							\
								utils/init_sound.c							\
								utils/init_ui.c								\
								utils/init_enemies_and_texture_checks.c		\
								utils/init_font_and_menus.c					\
								utils/init_textures.c						\
								utils/re_init_map.c							\
								utils/clean_up.c

SRCB			=				main.c										\
								main_loop.c									\
								utils/init.c								\
								utils/init_from_parser.c					\
								utils/init_texture.c						\
								utils/load_texture.c						\
								utils/saving.c								\
								draw/redraw.c								\
								draw/draw_grid.c							\
								draw/draw_panel.c							\
								draw/draw_panel_text.c						\
								draw/draw_texture_grid.c					\
								draw/erase_texture_grid.c					\
								input/key_input.c							\
								input/key_gridsize.c						\
								input/key_panel.c							\
								input/key_draw.c							\
								parser/parse_scan.c							\
								parser/parse_stage.c						\
								parser/parse_tier.c							\
								parser/parse_stock.c						\
								parser/parse_utils.c						\

OBJA				:=			$(addprefix $(OBJ_DIRA)/,$(SRCA:.c=.o))
OBJB				:=			$(addprefix $(OBJ_DIRB)/,$(SRCB:.c=.o))

#==============================================================================#
#------------------------------------------------------------------------------#
#                               COLORS FLAGS                                   #

R			=	\033[31m
G			=	\033[32m
B			=	\033[34m
W			=	\033[0m
O			=	\033[33m

#==============================================================================#
#------------------------------------------------------------------------------#
#                            COMPILER & FLAGS                                  #

CC					:=			gcc
CFLAGS				:=			-g -Wall -Wextra -Werror
OFLAGS				:=			-pipe
CFLAGS				+=			$(OFLAGS)
CLIB				:=			-L $(LIB_DIR) -lft
HEADER_DOOM			:=			$(INC_DIR)/doom_nukem.h
HEADER_EDITOR		:=			$(INC_DIR)/doom_editor.h

#==============================================================================#
#------------------------------------------------------------------------------#
#                                LIBRARY                                       #

L_FT				:=			$(LIB_DIR)

#==============================================================================#
#------------------------------------------------------------------------------#
#                                 RULES                                        #

all:					$(NAMEA) $(NAMEB)

doom:					$(NAMEA)

editor:					$(NAMEB)

$(NAMEA):				$(LIBFT) $(ARTA) $(OBJ_DIRA) $(OBJA)
	@printf "\n"
	@printf "\n"
	@printf "\t$(O)██████$(R)╗  $(O)██████$(R)╗  $(O)██████$(R)╗ $(O)███$(R)╗  $(O) ███$(R)╗  $(O)    ███$(R)╗ $(O)  ██$(R)╗$(O)██$(R)╗ $(O)  ██$(R)╗$(O)██$(R)╗ $(O) ██$(R)╗$(O)███████$(R)╗$(O)███$(R)╗ $(O)  ███$(R)╗\n"
	@printf "\t$(O)██$(R)╔══$(O)██$(R)╗$(O)██$(R)╔═══$(O)██$(R)╗$(O)██$(R)╔═══$(O)██$(R)╗$(O)████$(R)╗$(O) ████$(R)║  $(O)    ████$(R)╗ $(O) ██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)██$(R)║ $(O)██$(R)╔╝$(O)██$(R)╔════╝$(O)████$(R)╗ $(O)████$(R)║\n"
	@printf "\t$(O)██$(R)║ $(O) ██$(R)║$(O)██$(R)║$(O)   ██$(R)║$(O)██$(R)║  $(O) ██$(R)║$(O)██$(R)╔$(O)████$(R)╔$(O)██$(R)║$(O)█████$(R)╗$(O)██$(R)╔$(O)██$(R)╗$(O) ██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)█████$(R)╔╝$(O) █████$(R)╗ $(O) ██$(R)╔$(O)████$(R)╔$(O)██$(R)║\n"
	@printf "\t$(O)██$(R)║ $(O) ██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)██$(R)║╚$(O)██$(R)╔╝$(O)██$(R)║╚════╝$(O)██$(R)║╚$(O)██$(R)╗$(O)██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)██$(R)╔═$(O)██$(R)╗ $(O)██$(R)╔══╝ $(O) ██$(R)║╚$(O)██$(R)╔╝$(O)██$(R)║\n"
	@printf "\t$(O)██████$(R)╔╝╚$(O)██████$(R)╔╝╚$(O)██████$(R)╔╝$(O)██$(R)║ ╚═╝$(O) ██$(R)║ $(O)     ██$(R)║ ╚$(O)████$(R)║╚$(O)██████$(R)╔╝$(O)██$(R)║ $(O) ██$(R)╗$(O)███████$(R)╗$(O)██$(R)║ ╚═╝$(O) ██$(R)║\n"
	@printf "\t$(R)╚═════╝  ╚═════╝  ╚═════╝ ╚═╝     ╚═╝      ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝\n$(W)"
	@$(CC) $(OBJA) -o $(NAMEA) $(CLIB) `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -lpthread
	@printf '\033[40m %s\n\033[0m$(W)' "          Compilation of $(NAMEA) is done.        "
	@printf "\n"

$(NAMEB):				$(LIBFT) $(ARTB) $(OBJ_DIRB) $(OBJB)
	@printf "\n"
	@printf "\n"
	@printf "\t$(O)██████$(R)╗  $(O)██████$(R)╗  $(O)██████$(R)╗ $(O)███$(R)╗   $(O)███$(R)╗      $(O)███████$(R)╗$(O)██████$(R)╗ $(O)██$(R)╗$(O)████████$(R)╗ $(O)██████$(R)╗ $(O)██████$(R)╗ \n"
	@printf "\t$(O)██$(R)╔══$(O)██$(R)╗$(O)██$(R)╔═══$(O)██$(R)╗$(O)██$(R)╔═══$(O)██$(R)╗$(O)████$(R)╗ $(O)████$(R)║      $(O)██$(R)╔════╝$(O)██$(R)╔══$(O)██$(R)╗$(O)██$(R)║╚══$(O)██$(R)╔══╝$(O)██$(R)╔═══$(O)██$(R)╗$(O)██$(R)╔══$(O)██$(R)╗\n"
	@printf "\t$(O)██$(R)║  $(O)██$(R)║$(O)██$(R)║   $(O)██$(R)║$(O)██$(R)║   $(O)██$(R)║$(O)██$(R)╔$(O)████$(R)╔$(O)██$(R)║$(O)█████$(R)╗$(O)█████$(R)╗ $(O) ██$(R)║  $(O)██$(R)║$(O)██$(R)║   $(O)██$(R)║   $(O)██$(R)║   $(O)██$(R)║$(O)██████$(R)╔╝\n"
	@printf "\t$(O)██$(R)║  $(O)██$(R)║$(O)██$(R)║   $(O)██$(R)║$(O)██$(R)║   $(O)██$(R)║$(O)██$(R)║╚$(O)██$(R)╔╝$(O)██$(R)║╚════╝$(O)██$(R)╔══╝ $(O) ██$(R)║  $(O)██$(R)║$(O)██$(R)║   $(O)██$(R)║   $(O)██$(R)║   $(O)██$(R)║$(O)██$(R)╔══$(O)██$(R)╗\n"
	@printf "\t$(O)██████$(R)╔╝╚$(O)██████$(R)╔╝╚$(O)██████$(R)╔╝$(O)██$(R)║ ╚═╝ $(O)██$(R)║      $(O)███████$(R)╗$(O)██████$(R)╔╝$(O)██$(R)║   $(O)██$(R)║   ╚$(O)██████$(R)╔╝$(O)██$(R)║  $(O)██$(R)║\n"
	@printf "\t╚═════╝  ╚═════╝  ╚═════╝ ╚═╝     ╚═╝      ╚══════╝╚═════╝ ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝\n$(W)"
	@$(CC) $(OBJB) -o $(NAMEB) $(CLIB) `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer
	@printf '\033[40m %s\n\033[0m$(W)' "          Compilation of $(NAMEB) is done.               "
	@printf "\n"

$(OBJ_DIRA)/%.o:			$(SRC_DIRA)/%.c $(HEADER_DOOM)
	@printf "\033[33mCOMPILING\033[0m %s                                 \r" $<
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(INC_DIR) `sdl2-config --cflags`

$(OBJ_DIRB)/%.o:			$(SRC_DIRB)/%.c $(HEADER_EDITOR)
	@printf "\033[33mCOMPILING\033[0m %s                                 \r" $<
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(INC_DIR) `sdl2-config --cflags`

$(OBJ_DIRA):
	@mkdir -p $@
	@mkdir -p $@/engine
	@mkdir -p $@/parser
	@mkdir -p $@/utils
	@mkdir -p $@/gameplay
	@mkdir -p $@/menu

$(OBJ_DIRB):
	@mkdir -p $@
	@mkdir -p $@/draw
	@mkdir -p $@/input
	@mkdir -p $@/parser
	@mkdir -p $@/utils

$(LIBFT):
	@make -C $(L_FT) --no-print-directory
#	@brew install sdl2_ttf sdl2_mixer

clean:
	@make -C $(L_FT) clean --no-print-directory
	@rm -rf $(OBJ_DIRA) $(OBJ_DIRB)
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Clean of $(NAME) is done ---"


fclean: 				clean
	@rm -rf $(NAMEA)
	@rm -rf $(NAMEB)
	@make -C $(L_FT) fclean --no-print-directory
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Fclean of $(NAME) is done ---"

re:						fclean all

.PHONY: all clean fclean re build cbuild doom editor
