/*
** my_str_isprintable.c for my_str_isprintable in /home/bruere_s/Test
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sun Oct 18 17:18:31 2015 Sebastien BRUERE
** Last update Mon Oct 26 15:07:04 2015 Sebastien BRUERE
*/

int    my_str_isprintable(char *str)
{
  int   i;

  i = 0;
  if (str[0] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] >= 0 && str[i] <= 31)
	i++;
      else
	return (0);
    }
  return (1);
}
