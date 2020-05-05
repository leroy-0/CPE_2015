/*
** my_put_nbr.c for my_put_nbr in /home/bruere_s/rendu/Piscine_C_J08
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Fri Oct  9 11:59:18 2015 sebastien bruere
** Last update Thu Nov  5 09:40:45 2015 Sebastien BRUERE
*/

#include <unistd.h>
#include "../../include/my.h"

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -1 * nb;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar((nb % 10) + 48);
  return (nb);
}
