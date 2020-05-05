/*
** my.h for my in /home/bruere_s/rendu/Piscine_C_J09/include
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Fri Oct  9 12:55:12 2015 sebastien bruere
** Last update Sat Mar 26 15:04:29 2016 Sebastien BRUERE
*/

#ifndef MY_H_
# define MY_H_

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
char	*my_putnbr_base(int nbr, char *base);
char	*my_putstr_base(char *str);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
void	my_puterr(char *str);
void	my_putcerr(char c);
int		my_getnbr_base(char *str, char *base);
long		determine_power(char* str, int base);
int		my_strchar(char *str, char to_find);
int		my_len(char *str);

#endif /* !MY_H_ */
