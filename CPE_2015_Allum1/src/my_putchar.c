/*
** my_putchar.c for my_putchar in /home/leroy_0/rendu/Piscine_C_J07/lib/my
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Tue Oct  6 12:40:13 2015 maxime leroy
** Last update Wed Feb 10 15:14:37 2016 Tekm
*/

#include <unistd.h>
#include "../get_next_line/get_next_line.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
