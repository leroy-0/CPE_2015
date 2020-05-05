/*
** swap_elem.c for swap_elem in /home/leroy_0/rendu/CPE_year_Pushswap
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Wed Nov  4 14:20:02 2015 leroy_0
** Last update Sat Nov 21 18:52:15 2015 leroy_0
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

int	my_max(int *l_a, int size)
{
  int	a;
  int	value;

  a = 0;
  value = l_a[0];
  while (a != size)
    {
      if (value > l_a[a])
	a++;
      else
	{
	  value = l_a[a];
	  a++;
	}
    }
  return (value);
}

char	my_checker(int *l_a, int size)
{
  int	b;

  b = 0;
  while (b != size - 1 && (l_a[b] < l_a[b + 1]))
    b++;
  if (b == size - 1)
    {
      my_putchar('\n');
      return ('F');
    }
  return ('V');
}

int	my_algorithm(int *l_a, int size, int value_max)
{
  int	b;

  b = 0;
  while (b != size)
    {
      while (l_a[0] == value_max)
	my_ra(l_a, size);
      if (my_checker(l_a, size) == 'F')
	return (0);
      if (l_a[0] > l_a[1])
	{
	  my_sa(l_a);
	  if (my_checker(l_a, size) == 'F')
	    return (0);
	  my_ra(l_a, size);
	}
      else
	my_ra(l_a, size);
    }
  return (0);
}

int	main(int argc, char **argv)
{
  int	a;
  int	b;
  int	size;
  int	l_a[argc - 1];
  int	value_max;

  a = 0;
  b = 1;
  size = argc - 1;
  if (argc <= 2)
    {
      my_putchar('\n');
      return (0);
    }
  while (a < argc - 1)
    {
      l_a[a] = my_strint(argv[b]);
      a++;
      b++;
    }
  l_a[size] = '\0';
  value_max = my_max(l_a, size);
  my_algorithm(l_a, size, value_max);
  return (0);
}
