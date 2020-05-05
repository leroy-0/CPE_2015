/*
** mysh.c for mysh in /home/leroy_0/rendu/PSU_2015_minishell1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Jan  7 14:15:48 2016 leroy_0
** Last update Sun Feb 21 19:39:09 2016 Tekm
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../get_next_line/allum1.h"
#include "../get_next_line/get_next_line.h"

int		check_my_game(char **map)
{
  int		line;
  int		cpt;

  line = 0;
  cpt = 0;
  while (map[line])
    {
      while (map[line][cpt] != '|' && cpt != my_strlen(map[line]))
	cpt++;
      if ((my_strlen(map[line])) == cpt)
	{
	  line++;
	  cpt = 0;
	}
      else
	return (0);
    }
  return (1);
}

int		my_errors_l(int player, int line, char **map)
{
  int		cpt;

  cpt = 0;
  if (line == 0 || line > 4)
    {
      if (player == 1)
	my_putstr("Error: this line is out of range\n");
      return (1);
    }
  else if (line < 0)
    {
      if (player == 1)
	my_putstr("Error: invalid input (positive number expected)\n");
      return (1);
    }
  while (map[line][cpt] != '|' && cpt != my_strlen(map[line]))
    cpt++;
  if (cpt == my_strlen(map[line]))
    {
      if (player == 1)
	my_putstr("Error: this line is empty\n");
      return (1);
    }
  return (0);
}

int		my_prev_err(int player, int line, int nb_matches, char **map)
{
  int		save;
  int		cpt;

  cpt = 0;
  while (map[line][cpt] != '|' && cpt < my_strlen(map[line]))
    cpt++;
  save = cpt + nb_matches;
  while (cpt < save)
    {
      if (map[line][cpt] != '|')
	{
	  if (player == 1)
	    my_putstr("Error: not enough matches on this line\n");
	  return (1);
	}
      cpt++;
    }
  return (0);
}

int		my_errors_m(int player, int line, int nb_matches, char **map)
{
  if (nb_matches == 0)
    {
      if (player == 1)
	my_putstr("Error: you have to remove at least one match\n");
      return (1);
    }
  else if (nb_matches < 0)
    {
      if (player == 1)
	my_putstr("Error: invalid input (positive number expected)\n");
      return (1);
    }
  if (my_prev_err(player, line, nb_matches, map) == 1)
    return (1);
  return (0);
}

int		ai_turn(t_struct_d *data)
{
  data->line = (rand() % 10 + 1) / 2;
  data->nb_matches = (((rand() % 10 + 5) / 2) - 1);
  if (data->nb_matches <= 0)
    data->nb_matches = 1;
  while (my_errors_l(2, data->line, data->map) != 0)
    data->line = (rand() % 10 + 1) / 2;
  while (my_errors_m(2, data->line, data->nb_matches, data->map) != 0)
    {
      data->nb_matches = (((rand() % 10 + 5) / 2) - 1);
      if (data->nb_matches <= 0)
	data->nb_matches = 1;
    }
  my_putstr("AI's turn...\n");
  print_updated_board_game(data, 2);
  print_board(data);
  if (check_my_game(data->map) == 1)
    {
      my_putstr("I lost.. snif.. but I'll get you next time!!\n");
      return (1);
    }
  else
    my_putchar('\n');
  return (0);
}
