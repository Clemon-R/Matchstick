##
## Makefile for 102cipher in /home/raphael.goulmot/rendu/102cipher
## 
## Made by Raphaël Goulmot
## Login   <raphael.goulmot@epitech.net>
## 
## Started on  Tue Nov 29 15:57:16 2016 Raphaël Goulmot
## Last update Tue Feb 21 20:53:59 2017 Raphaël Goulmot
##

CC	=	gcc

SRC	=	src/utils/my_putstr_err.c	\
		src/utils/my_putchar.c		\
		src/utils/my_putstr.c		\
		src/utils/my_strlen.c		\
		src/utils/my_getnbr.c		\
		src/utils/my_put_nbr.c		\
		src/utils/get_next_line.c	\
		src/utils/my_is.c		\
		src/core/matchstick.c		\
		src/core/map.c			\
		src/core/display.c		\
		src/core/player.c		\
		src/core/AI.c			\
		src/core/main.c			\
		include/get_next_line.h		\
		include/matchstick.h		\
		include/map.h			\
		include/display.h		\
		include/player.h		\
		include/AI.h			\
		include/utils.h

OBJ	=	$(SRC:.c=.o)

TMP	=	$(OBJ:.h=.h~)

CFLAGS	=	-Wextra -Wall -Iinclude

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(TMP)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)
