/*
** myè_getnbr_base.c for myè_getnbr_base in /home/bruere_s/Projet/Corewar
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sat Mar 26 14:51:26 2016 Sebastien BRUERE
** Last update Sat Mar 26 14:56:25 2016 Sebastien BRUERE
*/

int		my_len(char *str)
{
  int		occur;
  char		*curr;

  occur = 0;
  curr = str;
  while (*curr != '\0')
    {
      occur++;
      curr++;
    }
  return (occur);
}

int		my_strchar(char *str, char to_find)
{
  int		len;
  int		i;

  if (!to_find)
    return (0);
  i = 0;
  len = my_len(str);
  while (i < len)
    {
      if (*(str + i) == to_find)
	return (i);
      ++i;
    }
  return (0);
}

long		determine_power(char* str, int base)
{
  long long	power;
  int		j;

  power = 1;
  j = 1;
  while (j++ < my_len(str))
    power *= base;
  return (power);
}

int		my_getnbr_base(char *str, char *base)
{
  long long	power;
  int		j;
  long long	ret;
  int		minus;

  minus = 0;
  ret = 0;
  if (!str)
    return (0);
  if (*str == '-')
    {
      minus = - 1;
      str++;
    }
  power = determine_power(str, my_len(base));
  j = 0;
  while (j++ < my_len(str))
    {
      ret += my_strchar(base, *(str + j - 1)) * power;
      power /= my_len(base);
    }
  if (minus == - 1)
    return (- ret);
  return (ret);
}
