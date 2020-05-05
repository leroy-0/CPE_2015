/*
** my_swap.c for my_swap in /home/bruere_s/rendu/Piscine_C_J08
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Fri Oct  9 12:42:34 2015 sebastien bruere
** Last update Fri Oct 23 11:12:29 2015 Sebastien BRUERE
*/

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
