/*
** my_strncpy.c for my_strncpy in /home/bruere_s/rendu/Piscine_C_J08
** 
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
** 
** Started on  Fri Oct  9 12:36:27 2015 sebastien bruere
** Last update Fri Oct  9 12:38:08 2015 sebastien bruere
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  if (i < n)
    dest[i] = '\0';
  return (dest);
}
