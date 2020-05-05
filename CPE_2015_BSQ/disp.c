/*
** disp.c for disp in /home/leroy_0/rendu/CPE_2015_BSQ
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Wed Dec 16 21:06:57 2015 leroy_0
** Last update Fri Dec 18 08:23:54 2015 leroy_0
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "include/my.h"
#include "include/struct.h"

void    my_display_bsq(t_struct_data *data)
{
  int   a;
  int   b;

  b = 0;
  while (b++ < data->line)
    {
      a = 0;
      while (a++ < data->maxline - 1)
        {
          if (data->tab[a][b] == 0)
            my_putchar('o');
          else if (data->tab[a][b] == -2)
            my_putchar('\n');
          else if (data->tab[a][b] == -3)
            my_putchar('x');
	  else
	    my_putchar('.');
	}
      my_putchar('\n');
    }
}

void    display(t_struct_data *data, int max, int positionx,
		int positiony)
{
  int   a;
  int   b;

  b = positionx;
  while (positionx > b - max)
    {
      a = positiony;
      while (positiony > a - max)
	data->tab[positionx][positiony--] = -3;
      positiony = a;
      positionx--;
    }
  my_display_bsq(data);
}

void    my_alloc_bsq(t_struct_data *data, t_struct_value *value)
{
  my_alloc(data);
  data->savecol = malloc(sizeof(int) * data->maxline);
  data->savefinal = malloc(sizeof(int) * data->maxline);
  value->row = 0;
  while (value->row++ < data->maxline)
    {
      data->savefinal[value->row] = 0;
      data->savecol[value->row] = 0;
    }
  value->row = 1;
  value->cpt = 1;
  value->count = 1;
  value->yes = 1;
}
