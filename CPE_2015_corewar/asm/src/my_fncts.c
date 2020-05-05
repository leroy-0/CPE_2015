/*
** my_fncts.c for my_fncts in /home/tekm/tek1/CPE_2015_corewar/asm
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Sun Mar 27 22:10:23 2016 Tekm
** Last update Sun Mar 27 23:33:47 2016 Tekm
*/

#include "my.h"

double		power(double x, int n)
{
  if (n == 0)
    return (1.0);
  else
    return (x * power( x , n - 1 ));
}

int             binary(int n)
{
  int           decimal;
  int           rem;
  int           i;

  i = 0;
  decimal = 0;
  while (n != 0)
    {
      rem = n % 10;
      n /= 10;
      decimal += rem * power(2, i);
      i++;
    }
  return (decimal);
}

char                    *hexa(unsigned long nb, int basenb, char *base)
{
  char		        *res;
  long int	        a;
  long int	        b;

  a = 0;
  b = 0;
  if ((res = malloc(50)) == NULL)
    exit(1);
  if (nb == 0)
    res[a] = '0';
  while (nb != 0)
    {
      b = nb % basenb;
      res[a] = base[b];
      nb = nb / basenb;
      a++;
    }
  my_revstr(res);
  return (res);
}

unsigned long           hexa_int(char *a, unsigned int len)
{
  unsigned long val;
  unsigned int i;

  i = 0;
  val = 0;
  while (i < len)
    {
      if (a[i] <= 57)
        val += (a[i] - 48) * (1 << (4 * (len - 1 - i)));
      else
        val += (a[i] - 55) * (1 << (4 * (len - 1 - i)));
      i++;
    }
  return (val);
}
