/*
** map.c for map in /home/bruere_s/Projet/Corewar
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Fri Mar 25 00:37:43 2016 Sebastien BRUERE
** Last update Sun Mar 27 19:48:55 2016 Sebastien BRUERE
*/

#include        <stdio.h>
#include        <sys/types.h>
#include        <sys/stat.h>
#include        <fcntl.h>
#include        <unistd.h>
#include        <stdlib.h>
#include        "vm.h"
#include        "op.h"

int		load_champ_in_map(t_champ *champ, t_all *all)
{
  char		*map;
  int		size;
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  k = 0;
  all->map = init_map();
  size = size_between_champ(all->nb_champion, champ);
  while (j < all->nb_champion)
    {
      while (k < champ[j].size)
	{
	  all->map[i] = j + 49;
	  i++;
	  k++;
	}
      j++;
      k = 0;
      i += size;
    }
}

int		size_between_champ(int nb, t_champ *champ)
{
  int		j;
  int		size;

  size = 0;
  j = 0;
  while (j < nb)
    {
      size += champ[j].size;
      j++;
    }
  size = MEM_SIZE - size;
  size = size / nb;
  return (size);
}

char		*init_map()
{
  char		*map;
  int		i;

  i = 0;
  map = malloc(sizeof(char) * (MEM_SIZE + 1));
  while (i < MEM_SIZE)
    {
      map[i] = '+';
      i++;
    }
  map[i] = '\0';
  return (map);
}
