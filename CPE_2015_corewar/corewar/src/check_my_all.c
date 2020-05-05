/*
** check_my_all.c for check_all in /home/longle_h/rendu/Corewar
**
** Made by Henri Longle
** Login   <longle_h@epitech.net>
**
** Started on  Sun Mar 27 15:43:40 2016 Henri Longle
** Last update Sun Mar 27 23:11:11 2016 Sebastien BRUERE
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"my.h"
#include		"vm.h"

void			my_check_champion_real(char *av, int j,
					       t_all *all, t_champion **head)
{
  if (av[j] == '.')
    j++;
  else
    {
      opt_help(head, "faux", all);
      exit(1);
    }
  if (av[j] && av[j] == 'c')
    {
      j++;
      if (av[j] && av[j] == 'o')
	j++;
      else
	{
	  opt_help(head, "faux", all);
	  exit(1);
	}
      if (av[j] && av[j] == 'r' && av[j + 1] == '\0')
	return ;
    }
  else
    {
      opt_help(head, "faux", all);
      exit(1);
    }
}

void			error()
{
  my_putstr(HIGHLIGHT);
  my_putstr(RED);
  my_putstr("Error : the number of champions must be between 2 and 4\n");
  my_putstr(DEFAULT);
  exit (10);
}

int			check_champion(char **av, t_champion **head, t_all *all)
{
  int			i;
  int			j;

  i = 1;
  j = 0;
  while (av[i] != NULL)
    {
      j = my_strlen(av[i]);
      while (av[i][j] != '.' && j > 0)
	j--;
      if (av[i][j] == '.')
	{
	  my_nb_champion(av[i], j, all, head);
	}
      j = 0;
      i++;
    }
  if ((all->nb_champion) <= 1 || (all->nb_champion)  > 4)
    error();
  return (0);
}

int			check_arg(char *arguments)
{
  int			i;

  i = 0;
  while (arguments[i] != '\0')
    {
      if (arguments[i] > '9' || arguments[i] < '0')
	{
	  my_putstr("Error : the arguments \
of dump is obligatory a positive number\n\n");
	  return (1);
	}
      i++;
    }
  return (0);
}

void			check_my_arguments(char **av,
				   t_ptr_fnct *tabs, t_all *all, int ac)
{
  int			i;
  int			j;
  int			a;

  i = 0;
  j = 0;
  while (av[++i] != NULL)
    {
      while (j <= 3 && my_strcmp(av[i], tabs[j].opt) != 0)
	j++;
      if (j == 4)
	j--;
      if (my_strcmp(av[i], tabs[j].opt) == 0)
	i ++;
      else
	{
	  a = my_strlen(av[i]);
	  while (a > 0 && av[i][a] != '.')
	    a--;
	  my_check_champion_real(av[i], a, all, &all->champion);
	}
      j = 0;
      if (i + 1 > ac)
	return ;
    }
}
