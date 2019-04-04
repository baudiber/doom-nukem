# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baudiber <baudiber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/20 22:43:42 by baudiber          #+#    #+#              #
#    Updated: 2019/03/31 18:46:49 by baudiber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	doom-nukem

SRC_DIR		=	./srcs
INC_DIR		=	./includes
OBJ_DIR		=	./objs
LIBFT_DIR	=	./libft

SRC			=	main.c								\
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
				parser/fake_parse.c					\
				menu/menu.c							\
				menu/menu_2.c						\
				menu/menu_options.c					\
				menu/menu_options_slider.c			\
				utils/init.c						\
				utils/init_vars.c					\
				utils/init_sound.c					\
				utils/init_ui.c						\
				utils/init_textures.c

R			=	\033[31m
G			=	\033[32m
B			=	\033[34m
W			=	\033[0m
O			=	\033[33m
CC 			=	gcc
FLAGS		=	-g -Wall -Werror -Wextra
INCLUDES	=	-I $(INC_DIR)
HEADER_H	=	$(INC_DIR)/doom_nukem.h
OBJ 		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
LIBS 		=	-L $(LIBFT_DIR) -lft

all: art $(NAME)

$(NAME): lib $(HEADER_H) $(OBJ)
	@$(CC)  $(OBJ) -o $(NAME) $(LIBS) `sdl2-config --libs` -lSDL2_ttf -lSDL2_mixer
	@echo "$(NAME) executable $(G)created$(W).                                                                "

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c $(HEADER_H) | $(OBJ_DIR)
	@printf "$(O)COMPILING$(W) %s                                  \r" $<
	@$(CC) -o $@ -c $< $(FLAGS) -I $(INC_DIR) `sdl2-config --cflags`

$(OBJ_DIR):
	@mkdir -p $@
	@mkdir -p $@/engine
	@mkdir -p $@/parser
	@mkdir -p $@/utils
	@mkdir -p $@/gameplay
	@mkdir -p $@/menu

lib:
	@make -C $(LIBFT_DIR)
#	@brew install sdl2_ttf sdl2_mixer

art:
	@printf "$(O)██████$(R)╗  $(O)██████$(R)╗  $(O)██████$(R)╗ $(O)███$(R)╗  $(O) ███$(R)╗  $(O)    ███$(R)╗ $(O)  ██$(R)╗$(O)██$(R)╗ $(O)  ██$(R)╗$(O)██$(R)╗ $(O) ██$(R)╗$(O)███████$(R)╗$(O)███$(R)╗ $(O)  ███$(R)╗\n"
	@printf "$(O)██$(R)╔══$(O)██$(R)╗$(O)██$(R)╔═══$(O)██$(R)╗$(O)██$(R)╔═══$(O)██$(R)╗$(O)████$(R)╗$(O) ████$(R)║  $(O)    ████$(R)╗ $(O) ██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)██$(R)║ $(O)██$(R)╔╝$(O)██$(R)╔════╝$(O)████$(R)╗ $(O)████$(R)║\n"
	@printf "$(O)██$(R)║ $(O) ██$(R)║$(O)██$(R)║$(O)   ██$(R)║$(O)██$(R)║  $(O) ██$(R)║$(O)██$(R)╔$(O)████$(R)╔$(O)██$(R)║$(O)█████$(R)╗$(O)██$(R)╔$(O)██$(R)╗$(O) ██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)█████$(R)╔╝$(O) █████$(R)╗ $(O) ██$(R)╔$(O)████$(R)╔$(O)██$(R)║\n"
	@printf "$(O)██$(R)║ $(O) ██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)██$(R)║╚$(O)██$(R)╔╝$(O)██$(R)║╚════╝$(O)██$(R)║╚$(O)██$(R)╗$(O)██$(R)║$(O)██$(R)║ $(O)  ██$(R)║$(O)██$(R)╔═$(O)██$(R)╗ $(O)██$(R)╔══╝ $(O) ██$(R)║╚$(O)██$(R)╔╝$(O)██$(R)║\n"
	@printf "$(O)██████$(R)╔╝╚$(O)██████$(R)╔╝╚$(O)██████$(R)╔╝$(O)██$(R)║ ╚═╝$(O) ██$(R)║ $(O)     ██$(R)║ ╚$(O)████$(R)║╚$(O)██████$(R)╔╝$(O)██$(R)║ $(O) ██$(R)╗$(O)███████$(R)╗$(O)██$(R)║ ╚═╝$(O) ██$(R)║\n"
	@printf "$(R)╚═════╝  ╚═════╝  ╚═════╝ ╚═╝     ╚═╝      ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝\n$(W)"

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY: all art lib clean fclean re
