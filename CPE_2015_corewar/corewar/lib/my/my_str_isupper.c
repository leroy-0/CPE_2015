/*
** my_str_isupper.c for my_str_isupper in /home/bruere_s/Test
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sun Oct 18 17:12:42 2015 Sebastien BRUERE
** Last update Mon Oct 26 15:07:19 2015 Sebastien BRUERE
*/

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] >= 65 && str[i] <= 90)
	i++;
      else
	return (0);
    }
  return (1);
}
