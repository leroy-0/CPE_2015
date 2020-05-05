/*
** check_my_champion.c for check_my_champion in /home/longle_h/rendu/Corewar
**
** Made by Henri Longle
** Login   <longle_h@epitech.net>
**
** Started on  Sun Mar 27 15:42:46 2016 Henri Longle
** Last update Sun Mar 27 23:12:28 2016 Sebastien BRUERE
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"my.h"
#include		"vm.h"

void			my_nb_champion(char *av, int j,
				       t_all *all, t_champion **head)
{
  if (av[j] == '.')
    j++;
  if (av[j] && av[j] == 'c')
    {
      j++;
      if (av[j] && av[j] == 'o')
	j++;
      if (av[j] && av[j] == 'r' && av[j + 1] == '\0')
	{
	  *head = putin(head, av);
	  all->nb_champion++;
	}
      else
	{
	  my_putstr(HIGHLIGHT);
	  my_putstr(RED);
	  my_putstr("Error : ");
	  my_putstr(av);
	  my_putstr(" is not a champion\n");
	  my_putstr(DEFAULT);
	  exit (1);
	}
    }
}

int			this_is_champ(char *av, int j,
				      t_all *all, t_champion **head)
{
  if (av[j] == '.')
    j++;
  else
    {
      my_putstr("Error : No champion specifed\n");
      exit(1);
    }
  if (av[j] && av[j] == 'c')
    {
      j++;
      if (av[j] && av[j] == 'o')
	j++;
      else
	{
	  my_putstr("Error : No champion specifed\n");
	  exit(1);
	}
      if (av[j] && av[j] == 'r' && av[j + 1] == '\0')
	return (1);
    }
  else
    {
      my_putstr("Error : No champion specifed\n");
      exit(1);
    }
}
