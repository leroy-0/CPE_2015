/*
** my_putchar.c for my_putchar in /home/bruere_s/rendu/Piscine_C_J08
** 
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
** 
** Started on  Fri Oct  9 11:57:37 2015 sebastien bruere
** Last update Sat Oct 17 01:04:25 2015 Sebastien BRUERE
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
