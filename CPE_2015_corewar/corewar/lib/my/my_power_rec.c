/*
** my_power_rec.c for my_power_rec in /home/bruere_s/rendu/Piscine_C_J08
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Fri Oct  9 11:54:37 2015 sebastien bruere
** Last update Fri Oct 23 11:21:34 2015 Sebastien BRUERE
*/

int	my_power_rec(int nb, int power)
{
  int	p;

  p = power;
  if (p == 0 || nb == 0)
    return (1);
  else if (p < 0)
    return (0);
  else if (p == 1)
    return (nb);
  return (nb * my_power_rec(nb, power - 1));
}
