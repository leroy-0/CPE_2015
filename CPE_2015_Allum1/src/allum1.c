/*
** mysh.c for mysh in /home/leroy_0/rendu/PSU_2015_minishell1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Jan  7 14:15:48 2016 leroy_0
** Last update Thu Feb 25 11:56:06 2016 Tekm
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../get_next_line/allum1.h"
#include "../get_next_line/get_next_line.h"

int             str_verify(char *str)
{
  int           a;

  a = 0;
  if (str == NULL || str[0] == '\0')
    return (1);
  while (str && str[a] != '\0')
    {
      if (str[a] < 48 || str[a] > 57)
        return (1);
      a++;
    }
  return (0);
}

int		do_that_game(t_struct_d *data, char *str)
{
  data->nb_matches = my_getnbr(str);
  if (my_errors_m(1, data->line, data->nb_matches, data->map) == 0)
    {
      print_updated_board_game(data, 1);
      print_board(data);
      if (check_my_game(data->map) == 1)
	{
	  my_putstr("You lost, too bad..\n");
	  return (0);
	}
      else
	my_putchar('\n');
      if (ai_turn(data) == 1)
	return (0);
      my_putstr("Your turn:\n");
    }
  return (1);
}

int		my_game(t_struct_d *data)
{
  char		*str;

  my_putstr("Matches: ");
  str = get_next_line(0);
  if (str_verify(str) == 1)
    {
      if (str == NULL)
	return (1);
      my_putstr("Error: invalid input (positive number expected)\n");
    }
  else
    {
      if (do_that_game(data, str) != 1)
	return (1);
    }
  return (0);
}

int		launch_game(t_struct_d *data)
{
  char		*str;

  my_putstr("Line: ");
  str = get_next_line(0);
  if (str_verify(str) == 1)
    {
      if (str == NULL)
	return (1);
      my_putstr("Error: invalid input (positive number expected)\n");
    }
  else
    {
      data->line = my_getnbr(str);
      if (my_errors_l(1, data->line, data->map) == 0)
	{
	  if (my_game(data) == 1)
	    return (0);
	}
    }
  return (-1);
}

int		main()
{
  t_struct_d	*data;

  data = malloc(sizeof(data) * 4);
  init_map(data);
  print_board(data);
  my_putstr("\nYour turn:\n");
  while (1)
    {
      if (launch_game(data) != -1)
	return (1);
    }
  return (0);
}
