/*
** my_putnbr.c for my_putnbr in /home/leroy_0/rendu/Piscine_C_J03
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Fri Oct  2 20:29:21 2015 maxime leroy
** Last update Thu Feb 11 16:38:10 2016 Tekm
*/

#include "../get_next_line/get_next_line.h"

int     my_put_nbr(int nb)
{
  int   a;

  a = 0;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb >= 10)
    {
      a = (nb % 10);
      nb = (nb - a) / 10;
      my_put_nbr(nb);
      my_putchar('0' + a);
    }
  else
    my_putchar('0' + nb % 10);
  return (0);
}
