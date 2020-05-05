##
## Makefile for Makefile in /home/leroy_0/rendu/Piscine_C_bistromathique
##
## Made by maxime leroy
## Login   <leroy_0@epitech.net>
##
## Started on  Wed Oct 28 13:45:12 2015 maxime leroy
## Last update Sun Mar 27 23:31:24 2016 Sebastien BRUERE
##

CC =		gcc

RM =		rm -Rf

CFLAGS =	-Wextra -Wall -W -pedantic

CFLAGS += 	-I./include

NAME =		asm

SRCS =  	src/asm.c \
		src/op.c \
		src/my_mains.c \
		src/my_fill.c \
		src/my_args.c \
		src/my_params.c \
		src/my_opts.c \
		src/my_fncts.c \
		src/my_getnbr.c \
		src/my_putchar.c \
		src/my_putstr.c \
		src/my_put_nbr.c \
		src/my_strlen.c \
		src/my_strcpy.c \
		src/my_strncpy.c \
		src/my_revstr.c \
		src/my_strcmp.c \
		src/my_strncmp.c \
		src/my_strcat.c \
		src/epur_str.c \
		src/get_next_line.c

OBJS =		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):		$(OBJS)
	  	$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
