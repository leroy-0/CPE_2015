/*
** my_op.c for my_op in /home/leroy_0/rendu/CPE_2015_Pushswap
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sat Nov 21 18:26:22 2015 leroy_0
** Last update Sat Nov 21 18:29:03 2015 leroy_0
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"

void    my_sa(int *l_a)
{
  int z;

  z = l_a[0];
  l_a[0] = l_a[1];
  l_a[1] = z;
  my_putstr("sa ");
}

void    my_ra(int *l_a, int size)
{
  int   a;
  int   z;

  z = 0;
  while (z != size - 1)
    {
      a = l_a[z];
      l_a[z] = l_a[z + 1];
      l_a[z + 1] = a;
      z++;
    }
  my_putstr("ra ");
}
