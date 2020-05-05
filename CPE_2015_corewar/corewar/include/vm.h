/*
** vm.h for vm in /home/bruere_s/Projet/Corewar/include
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sat Mar 26 22:18:38 2016 Sebastien BRUERE
** Last update Sun Mar 27 23:01:58 2016 Sebastien BRUERE
*/

#ifndef				VM_H_
# define			VM_H_

# define	DEFAULT		"\033[0m"
# define	HIGHLIGHT	"\033[1m"
# define	UNDERLINE	"\033[4m"
# define	BLANK		"\033[5m"
# define	BLACK		"\033[30m"
# define	RED		"\033[31m"
# define	GREEN		"\033[32m"
# define	YELLOW		"\033[33m"
# define	BLUE		"\033[34m"
# define	PURPLE		"\033[35m"
# define	CYAN		"\033[36m"
# define	WHITE		"\033[37m"

typedef struct			s_instructions
  {
    unsigned char		mnemo;
    int				num;
    char			*binary;
  } __attribute__ ((packed))	t_instruc;

typedef struct			s_champ
  {
    char			*name;
    int				num;
    int				size;
    int				pc;
    int				fd;
    int				carry;
    int				*reg;
    t_instruc			*inst;
  }				t_champ;

typedef struct			s_func
  {
    char			c;
    void			(*ptr)(t_instruc);
  }				t_func;

typedef struct			s_champion
  {
    int				nb;
    char			*name_file;
    int				load_adress;
    struct s_champion		*next;
  }				t_champion;

typedef struct			s_struct_all
  {
    int				nb_champion;
    char			**av;
    char			*args;
   int        nb_dump;
    char			*map;
    struct s_champion		*champion;
  }				t_all;

typedef struct			s_struct_ptr_fnct
  {
    char			*opt;
    int				(*ptr)(struct s_champion **,
				       char *arguments, struct s_struct_all *);
  }				t_ptr_fnct;

char				*my_convert_to_base(unsigned int nbr,
						    char *base);
int				my_strlen(char *str);
char				*my_revstr(char *str);
int				my_getnbr(char *str);
char				*my_strcpy(char *dest, char *src);
void				my_swap(char *a, char *b, char *c, char *d);
char				*do_swap(char *str);
char				*init_map();
int				load_champ_in_map(t_champ *champ, t_all *all);
void				display_map(char *map);
int				size_between_champ(int nb, t_champ *champ);
t_all				*parse_args(int ac, char **av);
t_instruc			*parse_file(t_champ champ);
void				my_nb_champion(char *av, int j,
					       t_all *all, t_champion **head);
void				my_check_champion_real(char *av,
						       int j, t_all *all,
						       t_champion **head);
int				this_is_champ(char *av, int j,
					      t_all *all, t_champion **head);
int				opt_help(t_champion **champion, char *arguments,
					 t_all *t_all);
int				opt_dump(t_champion **champion,
					 char *arguments, t_all *t_all);
int				opt_load(t_champion **champion,
					 char *arguments, t_all *all);
int				opt_nb_champ(t_champion **champion,
			     char *arguments, t_all *all);
t_champion			*putin(t_champion **champion, char *av);
int				check_champion(char **av,
					       t_champion **head, t_all *all);
int				check_arg(char *arguments);
void				check_my_arguments(char **av, t_ptr_fnct *tabs,
				   t_all *all, int ac);
void				my_check_champion_real(char *av, int j,
				       t_all *all, t_champion **head);
void				change_value_to_champ(t_all *all, int save,
						      char **av, int where);
int				my_next_arg_is_a_champion(t_all *all,
							  t_ptr_fnct *tabs,
							  int save, int where);
void				my_adrr_nb(int *i, t_all *all,
					   t_ptr_fnct *tabs, char *str);
void				show_my_struc(t_champion *tmp, t_all *all);
int				write_in_arena(t_champ champ);
int				display_error_open();
int				*init_reg(t_champion *tmp);
void				free_all(t_all *all, t_champ *champ,
					 t_instruc *inst);

#endif				/* !VM_H_ */
