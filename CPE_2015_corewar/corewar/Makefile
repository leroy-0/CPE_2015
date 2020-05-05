##
## Makefile for Makefile in /home/bruere_s/rendu/Piscine_C_workshoplib
## 
## Made by sebastien bruere
## Login   <bruere_s@epitech.net>
## 
## Started on  Fri Oct 16 15:36:04 2015 sebastien bruere
## Last update Sun Mar 27 23:30:44 2016 Sebastien BRUERE
##

CFLAGS=	-W -Wall -Wextra -ansi

LIBPATH=lib/my

SRC=	src/main.c \
	src/op.c \
	src/map.c \
	src/basic.c \
	src/display.c \
	src/display_error.c \
	src/parsing.c \
	src/pars_binary.c \
	src/opt.c \
	src/free.c \
	src/write_in_arena.c \
	src/check_my_champion.c \
	src/check_my_all.c \
	src/load_change.c

SRCLIB=	$(LIBPATH)/my_put_nbr.c \
	$(LIBPATH)/my_getnbr.c \
	$(LIBPATH)/my_putstr.c \
	$(LIBPATH)/my_strcpy.c \
	$(LIBPATH)/my_putchar.c \
	$(LIBPATH)/my_strcmp.c \
	$(LIBPATH)/my_strncmp.c \
	$(LIBPATH)/my_strdup.c \
	$(LIBPATH)/my_getnbr_base.c \
	$(LIBPATH)/my_revstr.c \
	$(LIBPATH)/my_strcat.c \
	$(LIBPATH)/my_strlen.c \

BINPATH=lib

NAME=	$(BINPATH)/libmy.a

NAME2=	corewar

CC=	gcc

ARRC=	ar rc

RANLIB=	ranlib

LIB=	 -L$(BINPATH) -lmy

RM=	rm -f

INC=	-I include/

OBJ=	$(SRCLIB:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(ARRC) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)
	$(CC) -o $(NAME2) $(SRC) $(LIB) $(INC)

clean:
	$(RM) $(OBJ)
	$(RM) vgcore*
	$(RM) *~

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAME2)

re:	fclean all

.PHONY: all clean fclean re

