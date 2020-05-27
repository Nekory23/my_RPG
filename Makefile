##
## EPITECH PROJECT, 2019
## makefile
## File description:
## project
##

NAME	=	my_rpg

SRC	=	src/main.c				\
		src/change_map.c			\
		src/choose_png.c			\
		src/main_menu.c				\
		src/game.c				\
		src/get_dir.c				\
		src/move_chara.c			\
		src/error_handling.c			\
		src/interact_inv.c			\
		src/fill_struct/fill_struct.c		\
		src/fill_struct/fill_struct_play.c	\
		src/fill_struct/fill_inv_slots.c	\
		src/fill_struct/fill_struct_mouse.c	\
		src/fill_struct/fill_struct_quest.c	\
		src/fill_struct/fill_struct_hud.c	\
		src/fill_struct/fill_struct_fight.c	\
		src/fill_struct/create_button.c		\
		src/fill_struct/create_sprite.c		\
		src/fill_struct/create_text.c		\
		src/colisions/check_colision_x.c	\
		src/colisions/check_colision_y.c	\
		src/colisions/colision_map_zero_r.c	\
		src/colisions/colision_map_one_r.c 	\
		src/colisions/colision_map_two_r.c	\
		src/colisions/colision_map_zero_d.c	\
		src/colisions/colision_map_one_d.c	\
		src/colisions/colision_map_two_d.c	\
		src/colisions/colision_map_zero_u.c	\
		src/colisions/colision_map_one_u.c	\
		src/colisions/colision_map_two_u.c	\
		src/colisions/colision_map_zero_lf.c	\
		src/colisions/colision_map_one_lf.c	\
		src/colisions/colision_map_two_lf.c	\
		src/display/draw.c			\
		src/display/draw_quest_bubble.c		\
		src/display/display_hud.c		\
		src/display/display_help.c		\
		src/display/display_inventory.c		\
		src/display/display_cursor.c		\
		src/display/draw_map.c			\
		src/end/game_over.c			\
		src/end/my_destroy.c			\
		src/end/my_destroy_bis.c		\
		src/quest/quest.c			\
		src/quest/end_quest.c			\
		src/quest/fight.c			\
		src/quest/end_fight.c			\
		src/react_button/react_button_main.c	\
		src/react_button/react_button_pause.c	\
		src/react_button/react_button_htp.c	\
		src/react_button/react_button_choose.c	\
		src/react_button/react_button_fight.c	\
		$(wildcard util/*.c)

CC	=	gcc

CFLAGS	=	-W -Wextra -Wall

CPPFLAGS	=	-I./include/

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

CFFLAGS	=	tests/unit_tests.c -I./include --coverage -lcriterion

OBJ	=	$(SRC:.c=.o)

name	:	all

all	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug	:	CFLAGS += -g3
debug	:	re

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)		\
		rm -f *# 		\
		rm -f src/*# 		\
		rm -f include/*# 	\
		rm -f *~ 		\
		rm -f src/*~ 		\
		rm -f include/*~ 	\
		rm -f *.gcda 		\
		rm -f *.gcno		\
		tree

re	:	fclean all

.PHONY	:	name all debug clean fclean re
