/*
** my_strlen.c for my_strlen in /home/bruere_s/rendu/Piscine_C_J08
** 
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
** 
** Started on  Fri Oct  9 12:27:42 2015 sebastien bruere
** Last update Fri Oct  9 12:29:19 2015 sebastien bruere
*/

int	my_strlen(char *str)
{
  int	len;

  len = 0;
  while (*str != 0)
    {
      str++;
      len++;
    }
  return (len);
}
