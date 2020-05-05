/*
** my_strdup.c for my_strdup in /home/bruere_s/rendu/Piscine_C_J08
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Wed Oct  7 09:56:40 2015 sebastien bruere
** Last update Wed Nov  4 09:43:44 2015 Sebastien BRUERE
*/

#include <stdlib.h>
#include "../../include/my.h"

char	*my_strdup(char *src)
{
  int	length;
  char	*copy;
  int	i;

  i = 0;
  length = my_strlen(src);
  copy = malloc(length);
  while (src[i] != '\0')
    {
      copy[i] = src[i];
      i++;
    }
  return (copy);
}
