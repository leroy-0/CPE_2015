/*
** epur_str.c for epur_str in /home/leroy_0/rendu/PSU_2015_minishell1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Jan 25 12:24:59 2016 leroy_0
** Last update Thu Mar 31 12:15:18 2016 Tekm
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

char		*epur_str(char *str)
{
  char		*src;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((src = malloc(sizeof(char *) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
	    i = i + 1;
	  if (j > 0 && str[i] != '\0')
	    src[j++] = ' ';
	}
      src[j] = str[i];
      j = j + 1;
      i = i + 1;
    }
  src[j] = '\0';
  return (src);
}

char		*my_close_chaine(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	str[i] = '\0';
      i = i + 1;
    }
  return (str);
}

char		**my_close(char **tab, int n)
{
  int		i;

  i = 0;
  while (i < n)
    {
      tab[i] = my_close_chaine(tab[i]);
      i = i + 1;
    }
  return (tab);
}
