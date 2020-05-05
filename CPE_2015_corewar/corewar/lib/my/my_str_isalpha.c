/*
** my_str_isalpha.c for my_str_isalpha in /home/bruere_s/Test
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sun Oct 18 16:56:42 2015 Sebastien BRUERE
** Last update Mon Oct 26 15:06:23 2015 Sebastien BRUERE
*/

#include <stdio.h>

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] >= 65 && str[i] <= 90)
	i++;
      else if (str[i] >= 97 && str[i] <= 122)
	i++;
      else
	return (0);
    }
  return (1);
}
