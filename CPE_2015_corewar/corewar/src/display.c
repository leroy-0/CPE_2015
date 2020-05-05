/*
** display.c for display in /home/bruere_s/Projet/Corewar
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sat Mar 26 18:24:56 2016 Sebastien BRUERE
** Last update Thu Mar 31 12:11:10 2016 Tekm
*/

#include	<stdio.h>
#include	"vm.h"
#include	"op.h"
#include	"my.h"

void		display_map(char *map)
{
  int		i;

  i = 0;
  while (map[i] != '\0')
    {
      my_putchar(map[i]);
      i++;
      if (i % 100 == 0)
	my_putchar('\n');
    }
  my_putchar('\n');
}
