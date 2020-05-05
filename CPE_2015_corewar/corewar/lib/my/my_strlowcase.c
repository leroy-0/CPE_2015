/*
** my_strlowcase.c for my_strlowcase in /home/bruere_s/Test
** 
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
** 
** Started on  Sun Oct 18 16:55:42 2015 Sebastien BRUERE
** Last update Sun Oct 18 16:56:01 2015 Sebastien BRUERE
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 65 && str[i] <= 90)
	str[i] = str[i] + 32;
      i++;
    }
  return (str);
}

