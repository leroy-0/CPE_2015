/*
** opt.c for opt in /home/longle_h/rendu/Corewar
**
** Made by Henri Longle
** Login   <longle_h@epitech.net>
**
** Started on  Sun Mar 27 15:42:07 2016 Henri Longle
** Last update Sun Mar 27 23:04:49 2016 Sebastien BRUERE
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"my.h"
#include		"vm.h"

int			opt_help(t_champion **champion,
				 char *arguments, t_all *t_all)
{
  my_putstr(HIGHLIGHT);
  my_putstr(GREEN);
  my_putstr("Usage : ./corewar [-dump nbr_cycle] ");
  my_putstr("[[-n prog_number] [-a load_address ] prog_name] ...\n");
  my_putstr(DEFAULT);
  if (my_strcmp(arguments, "dump") == 0)
    my_putstr("\nDump:\nDump's option dump memory after nbr_cycle of \
execution (if the game has not finish)\nTo use the option -dump,       \
    you have to assign a positive number only once\n");
  else if (my_strcmp(arguments, "null") == 0)
    my_putstr("\nDump:\nTo use the option -dump, you have to \
    assign a positive number only once.\n");
  else if (my_strcmp(arguments, "false") == 0)
    {
      my_putstr("\nload address:\nTo use the option -a, you have" );
      my_putstr(" to assign a positive number only once.\n");
    }
  else if (my_strcmp(arguments, "nb_champs") == 0)
    my_putstr("\nNumber of champion:\n To use the option -n, you \
    have to assign a positive number only once.\n");
  my_putstr(DEFAULT);
  return (1);
}

void			check_the_number(char *arguments,
					 t_all *all, t_champion **champion)
{
  int			i;

  i = 0;
  while (arguments[i] != '\0')
    {
      if (arguments[i] < '0' || arguments[i] > '9')
	{
	  my_putstr(HIGHLIGHT);
	  my_putstr(RED);
	  my_putstr("Error : the dump's number could be \
a postive number\n\n");
	  my_putstr(DEFAULT);
	  opt_help(champion, "dump", all);
	  exit (1);
	}
      i++;
    }
}

int			opt_dump(t_champion **champion,
				 char *arguments, t_all *all)
{
  if (arguments == NULL)
    {
      opt_help(champion, "null", all);
      exit(1);
    }
  check_the_number(arguments, all, champion);
  if (all->nb_dump != 0)
    {
      my_putstr(HIGHLIGHT);
      my_putstr(RED);
      my_putstr("Error : the dump's number could be only assigned once\n\n");
      my_putstr(DEFAULT);
      opt_help(champion, "dump", all);
      exit(1);
    }
  all->nb_dump = my_getnbr(arguments);
  return (0);
}

int			opt_load(t_champion **champion,
				 char *arguments, t_all *all)
{
  int			i;

  i = 0;
  if (arguments == NULL)
    {
      opt_help(champion, "false", all);
      exit(1);
    }
  while (arguments[i] != '\0')
    {
      if (arguments[i] < '0' || arguments[i] > '9')
	{
	  my_putstr(HIGHLIGHT);
	  my_putstr(RED);
	  my_putstr("Error : the load_address's");
	  my_putstr(" number could be only assigned once\n\n");
	  my_putstr(DEFAULT);
	  opt_help(champion, "false", all);
	  exit (1);
	}
      i++;
    }
}

int			opt_nb_champ(t_champion **champion,
				     char *arguments, t_all *all)
{
  int			i;

  i = 0;
  if (arguments == NULL)
    {
      opt_help(champion, "dump", all);
      exit(1);
    }
  while (arguments[i] != '\0')
    {
      if (arguments[i] < '0' || arguments[i] > '9')
	{
	  opt_help(champion, "nb_champs", all);
	  exit (1);
	}
      i++;
    }
}
