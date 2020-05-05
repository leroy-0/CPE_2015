##
## Makefile for Make in /home/longle_h/rendu/CPE_2015_corewar
## 
## Made by Henri Longle
## Login   <longle_h@epitech.net>
## 
## Started on  Sun Mar 27 20:19:55 2016 Henri Longle
## Last update Sun Mar 27 23:30:16 2016 Sebastien BRUERE
##

CFLAGS =	-Wextra -Wall -W -pedantic

NAME	=	corewar

all	:	$(NAME)

$(NAME)	:
		make -Casm
		make -Ccorewar

clean	:
		make clean -Casm
		make clean -Ccorewar

fclean	:
		make fclean -Casm
		make fclean -Ccorewar

re	:	fclean	all

.PHONY	:	clean fclean all re $(NAME)
