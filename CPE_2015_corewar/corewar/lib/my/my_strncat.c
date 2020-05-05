/*
** my_strncat.c for my_strncat in /home/bruere_s/rendu/Piscine_C_J08
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Fri Oct  9 12:30:40 2015 sebastien bruere
** Last update Mon Oct 26 16:20:37 2015 Sebastien BRUERE
*/

#include <unistd.h>

int	my_strlen(char *str);

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	i2;

  i = 0;
  i2 = my_strlen(dest);
  while (src[i] != '\0' && i < nb)
    {
      dest[i2] = src[i];
      i2++;
      i++;
    }
  if (i < nb)
    dest[i] = '\0';
  dest[i2] = '\0';
  return (dest);
}
