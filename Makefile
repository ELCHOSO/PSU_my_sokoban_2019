##
## EPITECH PROJECT, 2019
## sokoban
## File description:
## makefile
##

SRC	=	src/cpy_original_map.c	\
		src/move.c			\
		src/dead_x.c             	\
		src/main.c     		\
		src/map_in_tab.c   		\
		src/win_lose.c	\
		src/reset_map.c	\
		src/check_map.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS = -I ./include -g3

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
