/*
** my_showstr.c for my_showstr in /home/bruere_s/rendu/Piscine_C_J08
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Fri Oct  9 12:05:35 2015 sebastien bruere
** Last update Thu Nov  5 09:42:25 2015 Sebastien BRUERE
*/

#include "../../include/my.h"

int	my_showstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
	{
	  my_putchar('\\');
	  my_putnbr_base(str[i], "0123456789abcdef");
	}
      else
	my_putchar(str[i]);
      i++;
    }
  return (0);
}
