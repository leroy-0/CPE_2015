/*
** mysh.c for mysh in /home/leroy_0/rendu/PSU_2015_minishell1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Jan  7 14:15:48 2016 leroy_0
** Last update Sun Feb 21 01:14:15 2016 Tekm
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../get_next_line/allum1.h"
#include "../get_next_line/get_next_line.h"

void		print_board(t_struct_d *data)
{
  int		a;

  a = 0;
  while (data->map[a])
    {
      my_putstr(data->map[a++]);
      my_putchar('\n');
    }
}

void		replace_line(t_struct_d *data, char *saveline, int player)
{
  if (player == 1)
    {
      my_putstr("Player removed ");
      my_put_nbr(data->nb_matches);
      my_putstr(" match(es) from line ");
      my_put_nbr(data->line);
      my_putchar('\n');
    }
  else
    {
      my_putstr("AI removed ");
      my_put_nbr(data->nb_matches);
      my_putstr(" match(es) from line ");
      my_put_nbr(data->line);
      my_putchar('\n');
    }
  saveline = my_revstr(saveline);
  data->map[data->line] = saveline;
}

int		update_board(t_struct_d *data, int player, int cpt, char *saveline)
{
  int		save;

  save = 0;
  save = cpt + data->nb_matches;
  while (cpt < save)
    {
      if (data->map[data->line][cpt] == '|')
	saveline[cpt] = ' ';
      else
	{
	  my_putstr("Error: not enough matches on this line\n");
	  return (0);
	}
      cpt++;
    }
  while (data->map[data->line][cpt])
    {
      saveline[cpt] = data->map[data->line][cpt];
      cpt++;
    }
  saveline[cpt] = '\0';
  replace_line(data, saveline, player);
  return (0);
}

void		print_updated_board_game(t_struct_d *data, int player)
{
  int		cpt;
  char		*saveline;

  cpt = 0;
  saveline = malloc(sizeof(char) * my_strlen(data->map[data->line]) + 1);
  data->map[data->line] = my_revstr(data->map[data->line]);
  while (data->map[data->line][cpt] != '|'
	 && cpt != my_strlen(data->map[data->line]))
    {
      saveline[cpt] = data->map[data->line][cpt];
      cpt++;
    }
  if (cpt == my_strlen(data->map[data->line]))
    my_putstr("Error: invalid input\n");
  else
    update_board(data, player, cpt, saveline);
}

void		init_map(t_struct_d *data)
{
  int		a;

  a = 0;
  data->map = malloc(sizeof(char *) * 7);
  while (a < 6)
    data->map[a++] = malloc(sizeof(char) * 10);
  data->map[a] = NULL;
  data->map[0] = "*********\0";
  data->map[1] = "*   |   *\0";
  data->map[2] = "*  |||  *\0";
  data->map[3] = "* ||||| *\0";
  data->map[4] = "*|||||||*\0";
  data->map[5] = "*********\0";
}
