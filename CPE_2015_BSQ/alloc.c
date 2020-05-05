/*
** alloc.c for alloc in /home/leroy_0/rendu/CPE_2015_BSQ
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Wed Dec 16 21:05:06 2015 leroy_0
** Last update Fri Dec 18 09:01:13 2015 leroy_0
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

void    get_buffer(t_struct_data *data)
{
  int   fd;
  int   a;

  a = 0;
  fd = open(data->filepath, O_RDONLY);
  if (fd == -1)
    {
      my_putstr("Error: Argument is not a valid file\n");
      exit(1);
    }
  data->buffer = malloc(sizeof(char) * 2);
  while (read(fd, data->buffer, 1))
    a++;
  free(data->buffer);
  data->buffer = malloc(sizeof(char) * a);
  fd = open(data->filepath, O_RDONLY);
  read(fd, data->buffer, a);
}

void    my_last_alloc(int a, int b, int c, t_struct_data *data)
{
  b = 0;
  while (b++ < data->line)
    {
      a = 0;
      while (a++ < data->maxline)
	{
	  if (data->buffer[c] == '.')
	    data->tab[a][b] = -1;
	  else if (data->buffer[c] == 'o')
	    data->tab[a][b] = 0;
	  else if (data->buffer[c] == '\n')
	    data->tab[a][b] = -2;
	  c++;
	}
    }
}
void    my_prev_alloc(int a, int b, int c, t_struct_data *data)
{
  a = c;
  while (data->buffer[a] != '\n')
    {
      data->maxline++;
      a++;
    }
  data->maxline += 1;
  data->tab = malloc(sizeof(*data->tab) * data->maxline);
  b = 0;
  while (b++ < data->maxline)
    data->tab[b] = malloc(sizeof(*data->tab[b]) * data->line);
  my_last_alloc(a, b, c, data);
}

void    my_alloc(t_struct_data *data)
{
  char	*line;
  int   a;
  int   b;
  int	c;

  a = 0;
  b = 0;
  data->line = 0;
  data->maxline = 0;
  while (data->buffer[a] != '\n')
    a++;
  c = a + 1;
  line = malloc(sizeof(char) * c);
  while (b < a)
    {
      line[b] = data->buffer[b];
      b++;
    }
  line[b] = '\0';
  data->line = my_getnbr(line);
  free(line);
  my_prev_alloc(a, b, c, data);
}
