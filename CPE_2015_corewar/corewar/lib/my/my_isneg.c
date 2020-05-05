/*
** my_isneg.c for my_isneg in /home/bruere_s/rendu/Piscine_C_J08
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Fri Oct  9 11:46:52 2015 sebastien bruere
** Last update Thu Nov  5 09:40:23 2015 Sebastien BRUERE
*/

#include <unistd.h>
#include "../../include/my.h"

int	my_isneg(int n)
{
  if (n < 0)
    {
      my_putchar('N');
    }
  else
    {
      my_putchar('P');
    }
  return (0);
}
