/*
** parsing.c for parsing in /home/klein_h/Documents/Corewar
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Sat Mar 26 18:47:46 2016 Arthur Klein
** Last update Sun Mar 27 23:15:04 2016 Sebastien BRUERE
*/
#include		<unistd.h>
#include		<stdlib.h>
#include		"my.h"
#include		"vm.h"

t_champion		*putin(t_champion **champion, char *av)
{
  static int		i = 1;
  static t_champion	*save = NULL;
  t_champion		*elem;

  if ((elem = malloc(sizeof(t_champion))) == NULL)
    return (NULL);
  elem->nb = i;
  i++;
  elem->load_adress = 0;
  elem->name_file = av;
  elem->next = *champion;
  elem->next = NULL;
  if (*champion == NULL)
    {
      save = elem;
      return (save);
    }
  save->next = elem;
  save = elem;
  return (*champion);
}

t_ptr_fnct		*init_data()
  {
    t_ptr_fnct		*tabs;

    tabs = malloc(sizeof(t_ptr_fnct) * 4);
    tabs[0].ptr = &opt_help;
    tabs[0].opt = "-help";
    tabs[1].ptr = &opt_dump;
    tabs[1].opt = "-dump";
    tabs[2].opt = "-n";
    tabs[2].ptr = &opt_nb_champ;
    tabs[3].opt = "-a";
    tabs[3].ptr = &opt_load;
    return (tabs);
  }

void			init_value(int *i, int *j, t_all *all)
{
  *i = 1;
  *j = 0;
  all->nb_champion = 0;
  all->nb_dump = 0;
}

void			load_arguments(int ac, t_all *all,
				       t_ptr_fnct *tabs)
{
  int			i;
  int			j;
  int			dump;
  t_champion		*tmp;
  int			save;

  init_value(&i, &j, all);
  check_champion(all->av, &all->champion, all);
  check_my_arguments(all->av, tabs, all, ac);
  while (all->av[i] != NULL)
    {
      while (j < 4)
	{
	  if (my_strcmp(all->av[i], tabs[j].opt) == 0)
	    (tabs[j].ptr)(&all->champion, all->av[i + 1], all);
	  if (my_strcmp(all->av[i], "-a") == 0)
	    my_adrr_nb(&i, all, tabs, "-n");
	  else if (my_strcmp(all->av[i], "-n") == 0)
	    my_adrr_nb(&i, all, tabs, "-a");
	  j++;
	}
      j = 0;
      i++;
    }
}

t_all			*parse_args(int ac, char **av)
{
  t_all			*all;
  t_ptr_fnct		*tabs;

  all = NULL;
  all = malloc(sizeof(t_all));
  all->champion = NULL;
  all->av = av;
  tabs = init_data();
  load_arguments(ac, all, tabs);
  return (all);
}
