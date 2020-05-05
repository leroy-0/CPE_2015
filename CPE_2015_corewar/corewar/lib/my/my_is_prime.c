/*
** my_is_prime.c for my_is_prime in /home/bruere_s/rendu/Piscine_C_J08
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Fri Oct  9 11:48:53 2015 sebastien bruere
** Last update Thu Oct 29 11:26:52 2015 Sebastien BRUERE
*/

int	my_put_nbr(int nb);

int	my_is_prime(int nb)
{
  int	i;

  i = 2;
  if (nb == 1 || nb == 0 || nb < 0)
    return (0);
  while (i < nb)
    {
      if (nb % i == 0)
	return (0);
      i++;
    }
  return (1);
}
