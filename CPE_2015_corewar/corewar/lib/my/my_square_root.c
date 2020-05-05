/*
** my_square_root.c for my_square_root in /home/bruere_s/rendu/Piscine_C_J08
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Fri Oct  9 12:09:10 2015 sebastien bruere
** Last update Thu Oct 29 11:27:12 2015 Sebastien BRUERE
*/

int	my_square_root(int nb)
{
  int	i;

  i = 1;
  if (nb == 0)
    return (0);
  while ((nb / 2) > i)
    {
      if (i * i == nb)
	return (i);
      i++;
    }
  return (0);
}
