/*
** my_strcmp.c for my_strcmp in /home/bruere_s/Test
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sun Oct 18 13:52:40 2015 Sebastien BRUERE
** Last update Wed Nov  4 09:42:41 2015 Sebastien BRUERE
*/

#include <stdlib.h>
#include "../../include/my.h"

int my_strcmp(char *s1, char *s2)
{
  int   a;

  a = 0;
  while (s2[a])
    {
      if (s1[a] < s2[a])
	return (-1);
      if (s1[a] > s2[a])
	return (1);
      a++;
    }
  if (s1[a] < s2[a])
    return (-1);
  if (s1[a] > s2[a])
    return (1);
  if (s2[a] == s1[a])
    return (0);
  return (0);
}
