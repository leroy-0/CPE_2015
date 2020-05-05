/*
** my.h for my.h in /home/leroy_0/rendu/Piscine_C_J09/ex_02
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Oct  8 13:42:23 2015 maxime leroy
** Last update Thu Mar 31 12:23:41 2016 Tekm
*/

#ifndef MY_H_
# define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "asm.h"

void 		my_putstr(char *);
void		my_putchar(char);
void		my_put_nbr(int);
int		my_getnbr(char *);
int    		my_strlen(char *);
char   		*my_strcpy(char *, char *);
char		*my_strncpy(char *, char *, int);
char   	 	*my_strcat(char *, char *);
int		my_strcmp(char *, char *);
int     	my_strcmp(char *, char *);
int     	my_strint(char *);
int     	my_strncmp(char *, char *, int);
char    	*my_strnbr(long);
char    	*my_revstr(char *);
char            *epur_str(char *);
int             binary(int);
char            *hexa(unsigned long, int, char *);
unsigned long   hexa_int(char *, unsigned int);
void            opt_ldi_lldi(t_struct_d *, char, int);
void            opt_fork_lfork(t_struct_d *, char, int);
void            opt_zjmp(t_struct_d *, char, int);
void            opt_sti(t_struct_d *, char, int);
void            opt_normal(t_struct_d *, char, int);
void            get_labelsup(t_struct_d *, int, int, char *);
void            get_labelinf(t_struct_d *, int, int, char *);
void            get_label(t_struct_d *, int, int);
void            get_params(t_struct_d *, int, int);
void            check_opt(t_struct_d *, int, int,
			  char *, char);
void            convert_arg(t_struct_d *);
void            my_binaries(t_struct_d *);
int             check_arg(char *, char **);
void            get_cmds(t_struct_d *, char *, char *, int);
void            get_arg(char *, t_struct_d *, char *);
void            fill_header_prog(header_t *, char *, int);
void            fill_comment(header_t *, char *, int);
void            main_while(t_struct_d *, char *, char *, int);
void            main_while2(t_struct_d *, char *, int);
void            get_values(char *, char *,
			   header_t *, t_struct_d *);
void            fill_zero(t_struct_d *, header_t);
int             init_all2(t_struct_d *, int);

#endif /* !MY_H_ */
