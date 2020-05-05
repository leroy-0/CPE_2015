/*
** my_putnbr_base.c for my_putnbr_base in /home/bruere_s/Projet/Piscine_C_infinadd/lib/my
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Thu Oct 29 14:02:10 2015 Sebastien BRUERE
** Last update Thu Nov  5 09:41:15 2015 Sebastien BRUERE
*/

#include <stdlib.h>
#include "../../include/my.h"

int	my_putnbr_base(int nbr, char *base)
{
  int	size;
  int	modu;
  int	i;
  char	*convert;

  i = 0;
  size = my_strlen(base);
  convert = malloc(40);
  if (nbr <= 15)
    my_putchar('0');
  while (nbr != 0)
    {
      modu = nbr % size;
      convert[i++] = base[modu];
      nbr = nbr / size;
    }
  my_putstr(my_revstr(convert));
  return (0);
}
