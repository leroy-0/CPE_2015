/*
** load_change.c for load_change in /home/klein_h/Documents/Corewar
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Sun Mar 27 17:28:45 2016 Arthur Klein
** Last update Sun Mar 27 23:07:46 2016 Sebastien BRUERE
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"my.h"
#include		"vm.h"

void 			change_value_to_champ(t_all *all,
					      int save, char **av, int where)
{
  static t_champion 	*tmp = NULL;

  if (tmp == NULL)
    tmp = all->champion;
  if (where == 0)
    {
      if (my_strcmp(av[save], "-n") == 0)
	tmp->nb = my_getnbr(av[save + 1]);
      else if (my_strcmp(av[save], "-a") == 0)
	tmp->load_adress = my_getnbr(av[save + 1]);
      if (my_strcmp(av[save + 2], "-a") == 0)
	tmp->load_adress = my_getnbr(av[save + 3]);
      else if (my_strcmp(av[save + 2], "-n") == 0)
	tmp->nb = my_getnbr(av[save + 3]);
    }
  else
    {
      if (my_strcmp(av[save], "-n") == 0)
	tmp->nb = my_getnbr(av[save + 1]);
      else if (my_strcmp(av[save], "-a") == 0)
	tmp->load_adress = my_getnbr(av[save + 1]);
    }
  if (tmp->next != NULL)
    tmp = tmp->next;
}

int			my_next_arg_is_a_champion(t_all *all,
						  t_ptr_fnct *tabs,
						  int save, int where)
{
  int 		a;
  t_champion 	*tmp;

  a = 0;
  if (all->args == NULL)
    {
      my_putstr(HIGHLIGHT);
      my_putstr(RED);
      my_putstr("Error : No champion specifed\n");
      my_putstr(DEFAULT);
      exit(1);
    }
  a = my_strlen(all->args);
  while (all->args && all->args[a] != '.' && a > 0)
    a--;
  if (this_is_champ(all->args, a, all, &all->champion) == 1)
    {
      change_value_to_champ(all, save, all->av, where);
    }
}

void			my_adrr_nb(int *i, t_all *all,
				   t_ptr_fnct *tabs, char *str)
{
  int 	save;

  if (all->av[*i + 2] && my_strcmp(all->av[*i + 2], str) == 0)
    {
      save = *i;
      all->args = all->av[*i + 4];
      if (my_strcmp(all->av[*i + 2], "-n") == 0)
	opt_nb_champ(&all->champion, all->av[*i + 3], all);
      else
	opt_load(&all->champion, all->av[*i + 3], all);
      my_next_arg_is_a_champion(all, tabs, save, 0);
      *i += 4;
    }
  else
    {
      save = *i;
      all->args = all->av[*i + 2];
      if (my_strcmp(all->av[*i], "-n") == 0)
	opt_nb_champ(&all->champion, all->av[*i + 1], all);
      else
	opt_load(&all->champion, all->av[*i + 1], all);
      my_next_arg_is_a_champion(all, tabs, save, 1);
      *i += 2;
    }
}
