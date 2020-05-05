/*
** my_strstr.c for my_strstr in /home/bruere_s/rendu/Piscine_C_J08
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Fri Oct  9 12:38:36 2015 sebastien bruere
** Last update Fri Oct 23 11:14:38 2015 Sebastien BRUERE
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;

  if (*str != '\0')
    {
      while (*str != 0)
	{
	  i = 0;
	  while (*str == to_find[i])
	    {
	      i++;
	      (*str)++;
	      if (to_find[i] == 0)
		return (str - i);
	    }
	  (*str)++;
	}
      return (0);
    }
  else
    return (0);
}
