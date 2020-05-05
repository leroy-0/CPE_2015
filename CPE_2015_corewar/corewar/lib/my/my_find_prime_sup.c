/*
** my_find_prime_sup.c for my_find_prime_sup in /home/bruere_s/rendu/Piscine_C_J08
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Fri Oct  9 11:44:47 2015 sebastien bruere
** Last update Thu Nov  5 09:41:44 2015 Sebastien BRUERE
*/

#include "../../include/my.h"

int	my_find_prime_sup(int nb)
{
  int	i;

  i = nb;
  if (i % 2 == 0)
    i++;
  while (i > 21478000)
    {
      if (my_is_prime(i) == 1)
	return (i);
      i = i + 2;
    }
  return (0);
}
