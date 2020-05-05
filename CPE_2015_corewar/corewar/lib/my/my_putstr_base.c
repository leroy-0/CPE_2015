/*
** my_putstr_base.c for my_putstr_base in /home/bruere_s/Projet/lib/my
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Thu Nov  5 18:10:52 2015 Sebastien BRUERE
** Last update Mon Feb  1 19:20:17 2016 Sebastien BRUERE
*/

#include "../../include/my.h"

void	my_putstr_base(char *str, char *base)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 0 && str[i] < 32) || str[i] >= 127)
	{
	  my_putchar('\\');
	  my_putnbr_base(str[i], base);
	  i++;
	}
      else
	{
	  my_putchar(str[i]);
	  i++;
	}
    }
}
