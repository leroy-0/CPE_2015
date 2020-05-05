/*
** my_strncpy.c for my_strncpy in /home/leroy_0/rendu/j_06
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Mon Oct  5 10:18:07 2015 maxime leroy
** Last update Sun Mar 27 19:05:06 2016 Tekm
*/

char	*my_strncpy(char *dest, char *src, int nb)
{
  int x;

  x = 0;
  while (src[x] && x < nb)
    {
      dest[x] = src[x];
      x++;
    }
  dest[x] = '\0';
  return (dest);
}
