/*
** my_getnbr.c for my_getnbr in /home/bruere_s/exo_simple
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Thu Oct 15 17:16:33 2015 sebastien bruere
** Last update Thu Oct 29 11:28:57 2015 Sebastien BRUERE
*/

#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"

int	my_neg(char *str, int i)
{
  int	dash;

  dash = 0;
  i = i - 1;
  while ((i >= 0 && (str[i] == '-' || str[i] == '+')))
    {
      if (str[i] == '-')
	dash++;
      i--;
    }
  return (dash);
}

int	my_getnbr(char *str)
{
  int	res;
  int	i;
  int	neg;

  if (str == NULL)
    return (0);
  i = 0;
  res = 0;
  while (str[i] && (str[i] < '0' || str[i] > '9'))
    i++;
  neg = my_neg(str, i);
  while (str[i] && (str[i] >= '0' && str[i] <='9'))
    res = res * 10 + (str[i++] - '0');
  if ((neg % 2) == 0)
    return (res);
  else
    return (-res);
}
