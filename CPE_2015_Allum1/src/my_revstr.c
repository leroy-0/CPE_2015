/*
** my_revstr.c for my_revstr in /home/leroy_0/rendu/Piscine_C_J06/ex_04
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Oct  5 11:18:46 2015 maxime leroy
** Last update Tue Feb 16 10:32:07 2016 Tekm
*/

#include <stdlib.h>
#include "../get_next_line/get_next_line.h"

char	*my_revstr(char *str)
{
  char		*tmp;
  int		x;
  int		y;

  x = 0;
  y = my_strlen(str) - 1;
  tmp = malloc(sizeof(char) * y + 2);
  while (y >= 0)
    {
      tmp[x] = str[y];
      x++;
      y--;
    }
  tmp[x] = '\0';
  return (tmp);
}
