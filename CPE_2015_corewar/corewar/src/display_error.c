/*
** display_error.c for display_error in /home/bruere_s/Projet/Corewar
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sun Mar 27 17:56:31 2016 Sebastien BRUERE
** Last update Sun Mar 27 18:02:26 2016 Sebastien BRUERE
*/

#include	<unistd.h>

int		display_error_open()
{
  write(2, "Error in function open while loading champion\n", 47);
  return (10);
}
