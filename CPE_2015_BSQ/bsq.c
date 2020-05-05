/*
** bsq.c for bsq in /home/leroy_0/rendu/CPE_2015_bsq
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Nov 30 17:14:28 2015 leroy_0
** Last update Fri Dec 18 09:38:12 2015 leroy_0
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

void	my_check_row(t_struct_data *data, t_struct_value *value,
		     t_struct_save *save)
{
  save->saverow = value->row;
  save->savecpt = value->cpt;
  value->row = save->prevrow;
  value->cpt = save->savecpt;
  while (value->row < save->saverow
	 && data->tab[value->row][value->cpt] != 0
	 && value->row < data->maxline - 1)
    value->row++;
  if (value->row == save->saverow)
    value->yes = 0;
  value->row = save->saverow;
  value->cpt = save->prevcpt;
  while (value->cpt < save->savecpt
	 && data->tab[value->row][value->cpt] != 0
	 && value->cpt < data->line)
    value->cpt++;
}

void	my_check_cpt(t_struct_data *data, t_struct_value *value,
		     t_struct_save *save)
{
  if (value->yes == 0 && value->cpt == save->savecpt
      && data->tab[value->row][value->cpt] != 0
      && data->tab[value->row][value->cpt] != -2)
    {
      value->yes = 1;
      if (value->count > save->max)
	{
	  save->max++;
	  save->positionx = value->row;
	  save->positiony = value->cpt;
	}
      value->row = save->saverow + 1;
      value->cpt = save->savecpt + 1;
      value->count++;
    }
  else
    value->yes = 0;
}

void	my_bsq(t_struct_data *data, t_struct_value *value,
	       t_struct_save *save)
{
  while (value->cpt <= data->line)
    {
      while (value->row <= data->maxline)
	{
	  save->prevcpt = value->cpt;
	  save->prevrow = value->row;
	  while (value->yes == 1)
	    {
	      my_check_row(data, value, save);
	      my_check_cpt(data, value, save);
	    }
	  value->row = save->prevrow;
	  value->row += 1;
	  value->cpt = save->prevcpt;
	  value->count = 1;
	  if (value->row <= data->maxline - 1)
	    value->yes = 1;
	}
      value->row = 1;
      value->cpt += 1;
      value->yes = 1;
    }
  display(data, save->max, save->positionx, save->positiony);
}

int	main(int argc, char **argv)
{
  t_struct_data		*data;
  t_struct_value	*value;
  t_struct_save		*save;

  if (argc != 2)
    {
      my_putstr("Usage : ./bsq map_file\n");
      return (1);
    }
  value = malloc(sizeof(*value));
  save = malloc(sizeof(*save));
  data = malloc(sizeof(*data));
  data->filepath = malloc(sizeof(char) * my_strlen(argv[1]));
  data->filepath = argv[1];
  save->max = 0;
  get_buffer(data);
  my_alloc_bsq(data, value);
  my_bsq(data, value, save);
  free(value);
  free(save);
  free(data);
  return (0);
}
