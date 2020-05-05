/*
** basic.c for basic in /home/bruere_s/Projet/Corewar
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sat Mar 26 22:22:14 2016 Sebastien BRUERE
** Last update Sun Mar 27 23:16:02 2016 Sebastien BRUERE
*/

#include        <stdlib.h>
#include        <unistd.h>
#include        "vm.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}

char		*my_convert_to_base(unsigned int nbr, char *base)
{
  int		size;
  int		modu;
  char		*convert;
  int		i;

  i = 0;
  size = my_strlen(base);
  convert = malloc(sizeof(char) * 100);
  while (nbr != 0)
    {
      modu = nbr % size;
      convert[i++] = base[modu];
      nbr = nbr / size;
    }
  while ((i % 8) != 0)
    convert[i++] = '0';
  convert[i] = '\0';
  return (my_revstr(convert));
}

void		my_swap(char *a, char *b, char *c, char *d)
{
  char		tmp1;
  char		tmp2;

  tmp1 = 0;
  tmp2 = 0;
  tmp1 = *a;
  if (b != NULL)
    tmp2 = *b;
  *a = *c;
  if (b != NULL)
    *b = *d;
  *c = tmp1;
  if (b != NULL)
    *d = tmp2;
}

char		*do_swap(char *str)
{
  int		i;
  int		c;
  char		buff;

  i = my_strlen(str) - 1;
  c = 0;
  while (c < (i / 2))
    {
      my_swap(&(str[c]), &(str[c + 1]), &(str[i - c]), &(str[i - (c + 1)]));
      c += 2;
    }
  c = 0;
  while ((c) < i)
    {
      my_swap(&(str[c]), NULL, &(str[c + 1]), NULL);
      c += 2;
    }
  return (str);
}
