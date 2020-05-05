/*
** get_next_line.h for get_next_line in /home/bruere_s/Projet/CPE_2015_corewar/asm/include
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sun Mar 27 23:25:13 2016 Sebastien BRUERE
** Last update Sun Mar 27 23:27:01 2016 Sebastien BRUERE
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

#ifndef		READ_SIZE
# define	READ_SIZE	(14)
#endif		/* !READ_SIZE */

char		*get_next_line(const int fd);
void		my_putchar(char c);
void		my_putstr(char *str);
int		my_strlen(char *str);
char		*my_revstr(char *str);
int		my_getnbr(char *str);
int		str_verify(char *str);

typedef struct	s_struct
{
  char		**map;
  int		player;
  int		line;
  int		nb_matches;
}		t_struct;

#endif		/* !GET_NEXT_LINE_H_ */
