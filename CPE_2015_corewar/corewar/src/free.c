/*
** free.c for free in /home/bruere_s/Projet/CPE_2015_corewar/corewar
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sun Mar 27 20:14:45 2016 Sebastien BRUERE
** Last update Sun Mar 27 20:39:26 2016 Sebastien BRUERE
*/

#include	<stdlib.h>
#include	"vm.h"

void		free_all(t_all *all, t_champ *champ, t_instruc *inst)
{
  int		i;

  i = 0;
  while (i < all->nb_champion)
    {
      free(champ[i].name);
      free(champ[i].reg);
      free(champ[i].inst);
      i++;
    }
  free(champ);
  free(all);
}
