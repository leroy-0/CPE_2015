/*
** main.c for main in /home/bruere_s/Projet/Corewar
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Wed Mar 23 20:11:46 2016 Sebastien BRUERE
** Last update Sun Mar 27 23:00:53 2016 Sebastien BRUERE
*/

#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"vm.h"
#include	"op.h"
#include	"my.h"

t_champ		parse_tab(t_champ champ, header_t *header)
{
  char		*s;
  int		b;

  s = NULL;
  b = 0;
  champ.name = malloc(sizeof(char) * (PROG_NAME_LENGTH + 1));
  champ.name = my_strcpy(champ.name, header->prog_name);
  s = my_convert_to_base(header->prog_size, "0123456789abcdef");
  s = do_swap(s);
  champ.size = my_getnbr_base(s, "0123456789abcdef");
  free(s);
  return (champ);
}

header_t	*read_header(int fd)
{
  header_t	*tab;

  tab = NULL;
  tab = malloc(sizeof(header_t));
  read(fd, tab, sizeof(header_t));
  return (tab);
}

int		*init_reg(t_champion *tmp)
{
  int		*reg;
  int		i;

  i = 0;
  reg = malloc(sizeof(int) * REG_NUMBER);
  while (i < REG_NUMBER)
    {
      if (i == 0)
	{
	  reg[i] = tmp->nb;
	  i++;
	}
      reg[i] = 0;
      i++;
    }
  return (reg);
}

t_champ		*fill_champ(t_champ *champ, t_all *all)
{
  int		j;
  header_t	*tab;
  t_champion 	*tmp;
  int		fd;

  j = 0;
  champ = NULL;
  tmp = all->champion;
  champ = malloc(sizeof(t_champ) * all->nb_champion);
  while (tmp != NULL)
    {
      if ((fd = open(tmp->name_file, O_RDONLY)) < 0)
	return (NULL);
      champ[j].num = tmp->nb;
      champ[j].fd = fd;
      champ[j].carry = 0;
      champ[j].reg = init_reg(tmp);
      tab = read_header(fd);
      champ[j] = parse_tab(champ[j], tab);
      tmp = tmp->next;
      j++;
    }
  return (champ);
}

int		main(int ac, char **av)
{
  t_champ	*champ;
  t_all		*all;
  t_instruc	*inst;
  int		i;
  int		cycles;

  i = 0;
  champ = NULL;
  cycles = CYCLE_TO_DIE;
  all = parse_args(ac, av);
  if ((champ = fill_champ(champ, all)) == NULL)
    return (display_error_open());
  load_champ_in_map(champ, all);
  while (cycles != 0)
    {
      while (i < all->nb_champion)
	{
	  champ[i].inst = parse_file(champ[i]);
	  write_in_arena(champ[i]);
	  i++;
	}
      cycles -= 1;
    }
  free_all(all, champ, inst);
  return (0);
}
