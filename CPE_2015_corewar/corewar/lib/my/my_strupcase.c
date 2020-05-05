/*
** my_strupcase.c for my_strupcase in /home/bruere_s/Test
** 
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
** 
** Started on  Sun Oct 18 14:46:00 2015 Sebastien BRUERE
** Last update Sun Oct 18 14:50:45 2015 Sebastien BRUERE
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 97 && str[i] <= 122)
	str[i] = str[i] - 32;
      i++;
    }
  return (str);
}
