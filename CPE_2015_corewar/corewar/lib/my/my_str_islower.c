/*
** my_str_islower.c for my_str_islower in /home/bruere_s/Test
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sun Oct 18 17:08:34 2015 Sebastien BRUERE
** Last update Mon Oct 26 15:05:56 2015 Sebastien BRUERE
*/

#include <stdio.h>

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] >= 97 && str[i] <= 122)
	i++;
      else
	return (0);
    }
  return (1);
}
