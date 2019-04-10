# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clrichar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 15:08:30 by clrichar          #+#    #+#              #
#    Updated: 2019/04/10 16:49:37 by baudiber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=				DOOM-NUKEM
NAMEA				:=				doom-nukem
NAMEB				:=				doom-editor

#==============================================================================#
#------------------------------------------------------------------------------#
#                               DIRECTORIES                                    #

SRC_DIR				:=			./srcs
INC_DIR				:=			./includes
OBJ_DIR				:=			./objs
LIB_DIR				:=			./libft
LIBFT				:=			./libft/libft.a

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  FILES                                       #

SRCA			=				main.c								\
								main_loop.c							\
								engine/engine_dda.c					\
								engine/engine_draw_walls.c			\
								engine/engine_floor_casting.c		\
								engine/engine_multithreading.c		\
								engine/engine_raycasting.c			\
								engine/engine_sprites.c				\
								engine/engine_sprites_utils.c		\
								engine/engine_draw_ceiling.c		\
								gameplay/player_movement.c			\
								gameplay/mouse_aim.c				\
								gameplay/move_player.c				\
								gameplay/ui.c						\
								gameplay/sprite_interaction.c		\
								gameplay/minimap.c					\
								gameplay/minimap_drawplayer.c		\
								gameplay/minimap_drawmap.c			\
								gameplay/weapon_switch.c			\
								gameplay/weapon_fire.c				\
								parser/parse_scan.c					\
								parser/parse_stage.c				\
								parser/parse_tier.c					\
								parser/parse_stock.c				\
								parser/parse_sprite.c				\
								parser/parse_utils.c				\
								menu/menu.c							\
								menu/menu_2.c						\
								menu/menu_options.c					\
								menu/menu_options_slider.c			\
								utils/init.c						\
								utils/init_vars.c					\
								utils/init_sound.c					\
								utils/init_ui.c						\
								utils/init_textures.c

SRCB			=				editor/main.c						\
								editor/init.c						\
								editor/init_texture.c				\
								editor/init_tab.c					\
								editor/engine_loop.c				\
								editor/editor.c					\
								editor/load_texture.c				\
								editor/draw_grid.c					\
								editor/draw_panel.c				\
								editor/draw_panel_text.c			\
								editor/draw_texture_grid.c			\
								editor/erase_texture_grid.c		\
								editor/key_input.c					\
								editor/key_gridsize.c				\
								editor/key_panel.c					\
								editor/key_draw.c					\
								editor/redraw.c					\
								editor/saving.c					\
								parser/parse_scan.c					\
								parser/parse_stage.c				\
								parser/parse_tier.c					\
								parser/parse_stock.c				\
								parser/parse_sprite.c				\
								parser/parse_utils.c				\

OBJA				:=			$(addprefix $(OBJ_DIR)/,$(SRCA:.c=.o))
OBJB				:=			$(addprefix $(OBJ_DIR)/,$(SRCB:.c=.o))

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


$(NAMEA):				$(LIBFT) $(ARTA) $(OBJ_DIR) $(OBJA)
	@printf "\n"
	@printf "\n"
	@printf "\t$(O)██████$(R)╗  $(O)██████$(R)╗  $(O)██████$(R)╗ $(O)███$(R)╗  $(O) ███$(R)╗  $(O)    ███$(R)╗ $(O)  ██$(R)╗$(O)██$(R)╗ $(O)  ██$(R)╗$(O)██$(R)╗ $(O) ██$(R)╗$(O)███████$(R)╗$(O)███$(R)╗ $(O)  ███$(R)╗\n"
	@printf "\t$(O)██$(R)╔══$(O)██$(R)╗$(O)██$(R)╔═══$(O)██$(R)╗$(O)██$(R)╔═══$(O)██$(R)╗$(O)████$(R)╗$(O) ████$(R)║  $(O)    ████$(R)╗ $(O) ██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)██$(R)║ $(O)██$(R)╔╝$(O)██$(R)╔════╝$(O)████$(R)╗ $(O)████$(R)║\n"
	@printf "\t$(O)██$(R)║ $(O) ██$(R)║$(O)██$(R)║$(O)   ██$(R)║$(O)██$(R)║  $(O) ██$(R)║$(O)██$(R)╔$(O)████$(R)╔$(O)██$(R)║$(O)█████$(R)╗$(O)██$(R)╔$(O)██$(R)╗$(O) ██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)█████$(R)╔╝$(O) █████$(R)╗ $(O) ██$(R)╔$(O)████$(R)╔$(O)██$(R)║\n"
	@printf "\t$(O)██$(R)║ $(O) ██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)██$(R)║╚$(O)██$(R)╔╝$(O)██$(R)║╚════╝$(O)██$(R)║╚$(O)██$(R)╗$(O)██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)██$(R)╔═$(O)██$(R)╗ $(O)██$(R)╔══╝ $(O) ██$(R)║╚$(O)██$(R)╔╝$(O)██$(R)║\n"
	@printf "\t$(O)██████$(R)╔╝╚$(O)██████$(R)╔╝╚$(O)██████$(R)╔╝$(O)██$(R)║ ╚═╝$(O) ██$(R)║ $(O)     ██$(R)║ ╚$(O)████$(R)║╚$(O)██████$(R)╔╝$(O)██$(R)║ $(O) ██$(R)╗$(O)███████$(R)╗$(O)██$(R)║ ╚═╝$(O) ██$(R)║\n"
	@printf "\t$(R)╚═════╝  ╚═════╝  ╚═════╝ ╚═╝     ╚═╝      ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝\n$(W)"
	@printf "\n"
	@$(CC) $(OBJA) -o $(NAMEA) $(CLIB) `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer -lpthread
	@printf '\033[33m[ 100%% ]\033[0m \033[40m %s\n\033[0m' "Compilation of $(NAMEA) is done."
	@printf ""

$(NAMEB):				$(LIBFT) $(ARTB) $(OBJ_DIR) $(OBJB)
	@printf "\n"
	@printf "\n"
	@printf "\t$(O)██████$(R)╗  $(O)██████$(R)╗  $(O)██████$(R)╗ $(O)███$(R)╗   $(O)███$(R)╗      $(O)███████$(R)╗$(O)██████$(R)╗ $(O)██$(R)╗$(O)████████$(R)╗ $(O)██████$(R)╗ $(O)██████$(R)╗ \n"
	@printf "\t$(O)██$(R)╔══$(O)██$(R)╗$(O)██$(R)╔═══$(O)██$(R)╗$(O)██$(R)╔═══$(O)██$(R)╗$(O)████$(R)╗ $(O)████$(R)║      $(O)██$(R)╔════╝$(O)██$(R)╔══$(O)██$(R)╗$(O)██$(R)║╚══$(O)██$(R)╔══╝$(O)██$(R)╔═══$(O)██$(R)╗$(O)██$(R)╔══$(O)██$(R)╗\n"
	@printf "\t$(O)██$(R)║  $(O)██$(R)║$(O)██$(R)║   $(O)██$(R)║$(O)██$(R)║   $(O)██$(R)║$(O)██$(R)╔$(O)████$(R)╔$(O)██$(R)║$(O)█████$(R)╗$(O)█████$(R)╗ $(O) ██$(R)║  $(O)██$(R)║$(O)██$(R)║   $(O)██$(R)║   $(O)██$(R)║   $(O)██$(R)║$(O)██████$(R)╔╝\n"
	@printf "\t$(O)██$(R)║  $(O)██$(R)║$(O)██$(R)║   $(O)██$(R)║$(O)██$(R)║   $(O)██$(R)║$(O)██$(R)║╚$(O)██$(R)╔╝$(O)██$(R)║╚════╝$(O)██$(R)╔══╝ $(O) ██$(R)║  $(O)██$(R)║$(O)██$(R)║   $(O)██$(R)║   $(O)██$(R)║   $(O)██$(R)║$(O)██$(R)╔══$(O)██$(R)╗\n"
	@printf "\t$(O)██████$(R)╔╝╚$(O)██████$(R)╔╝╚$(O)██████$(R)╔╝$(O)██$(R)║ ╚═╝ $(O)██$(R)║      $(O)███████$(R)╗$(O)██████$(R)╔╝$(O)██$(R)║   $(O)██$(R)║   ╚$(O)██████$(R)╔╝$(O)██$(R)║  $(O)██$(R)║\n"
	@printf "\t╚═════╝  ╚═════╝  ╚═════╝ ╚═╝     ╚═╝      ╚══════╝╚═════╝ ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝\n"
	@printf "\n"
	@$(CC) $(OBJB) -o $(NAMEB) $(CLIB) `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer
	@printf '\033[33m[ 100%% ]\033[0m \033[40m %s\n\033[0m' "Compilation of $(NAMEB) is done."
	@printf ""

$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c $(HEADER_DOOM) $(HEADER_EDITOR)
	@printf "\033[33mCOMPILING\033[0m %s                                 \r" $<
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(INC_DIR) `sdl2-config --cflags`

$(OBJ_DIR):
	@mkdir -p $@
	@mkdir -p $@/engine
	@mkdir -p $@/parser
	@mkdir -p $@/utils
	@mkdir -p $@/gameplay
	@mkdir -p $@/menu
	@mkdir -p $@/editor


$(LIBFT):
	@make -C $(L_FT) --no-print-directory
#	@brew install sdl2_ttf sdl2_mixer

clean:
	@make -C $(L_FT) clean --no-print-directory  
	@rm -rf $(OBJ_DIR)
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Clean of $(NAME) is done ---"


fclean: 				clean
	@rm -rf $(NAMEA)
	@rm -rf $(NAMEB)
	@make -C $(L_FT) fclean --no-print-directory
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Fclean of $(NAME) is done ---"

re:						fclean all

.PHONY: all clean fclean re build cbuild
