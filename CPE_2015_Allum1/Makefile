##
## Makefile for Makefile in /home/leroy_0/rendu/Piscine_C_bistromathique
##
## Made by maxime leroy
## Login   <leroy_0@epitech.net>
##
## Started on  Wed Oct 28 13:45:12 2015 maxime leroy
## Last update Thu Feb 11 17:11:14 2016 Tekm
##

CC =	gcc

RM =	rm -f

CFLAGS +=	-Wextra -Wall

NAME =	allum1

SRCS =  src/allum1.c \
	src/upboard.c \
	src/err.c \
	src/my_putchar.c \
	src/my_putstr.c \
	src/my_strlen.c \
	src/my_revstr.c \
	src/my_put_nbr.c \
	src/my_getnbr.c \
	get_next_line/get_next_line.c

OBJS =	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	  $(CC) -o $(NAME) $(SRCS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
