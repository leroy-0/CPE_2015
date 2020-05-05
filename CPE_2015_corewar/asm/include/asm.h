/*
** asm.h for asm in /home/bruere_s/Projet/CPE_2015_corewar/asm/include
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Sun Mar 27 23:27:35 2016 Sebastien BRUERE
** Last update Thu Mar 31 12:23:03 2016 Tekm
*/

#ifndef		ASM_H_
# define	ASM_H_

#include	"my.h"
#include	"op.h"

typedef struct	s_struct_d
{
  char		**cmds;
  char		**label;
  char		*saveinst;
  int		nbinst;
  char		inst[MEM_SIZE];
  char		*end;
  int		cpt_inst;
  int		cpt_c;
  int		lines;
  int		nbtype;
  char		*name;
  char		*path;
  int		turn;
  int		id;
  int		fd;
}		t_struct_d;

#endif		/* !ASM_H_ */
