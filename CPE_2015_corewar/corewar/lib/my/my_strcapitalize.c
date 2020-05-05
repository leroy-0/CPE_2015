/*
** my_strcapitalize.c for my_strcapitalize in /home/bruere_s/Test
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sun Oct 18 16:58:19 2015 Sebastien BRUERE
** Last update Wed Oct 28 15:38:40 2015 Sebastien BRUERE
*/

#include <stdio.h>

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  if (str[i] >= 'a' && str[i] <= 'z')
    str[i] = str[i] - 32;
  while (str[i] != '\0')
    {
      if (str[i] == '+' || str[i] == '-')
	str[i + 1] = str[i + 1] - 32;
      if (str[i] == ' '|| (str[i] >= '!' && str[i] <= '*'))
	{
	  if (str[i] == ' ' || (str[i] >= ':' && str[i] <= '@'))
	    {
	      if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
		{
		  str[i + 1] = str[i + 1] - 32;
		  i++;
		}
	    }
	}
      i++;
    }
  return (str);
}
