/*
** my_str_isnum.c for my_str_isnum in /home/bruere_s/Test
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sun Oct 18 17:01:23 2015 Sebastien BRUERE
** Last update Mon Oct 26 15:06:46 2015 Sebastien BRUERE
*/

#include <stdio.h>

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	i++;
      else
	return (0);
    }
  return (1);
}
