/*
** pars_binary.c for parse_binary in /home/longle_h/rendu/Corewar
**
** Made by Henri Longle
** Login   <longle_h@epitech.net>
**
** Started on  Sat Mar 26 23:16:25 2016 Henri Longle
** Last update Sun Mar 27 20:38:07 2016 Henri Longle
*/

#include        <stdio.h>
#include        <sys/types.h>
#include        <sys/stat.h>
#include        <fcntl.h>
#include        <unistd.h>
#include        <stdlib.h>
#include        "vm.h"
#include        "op.h"
#include        "my.h"

int		parse_binary(t_instruc *inst)
{
  static int           i = 0;

  if (i == 8)
    i = 0;
  while ((i < 8) && (inst->binary[i + 1] != '\0'))
    {
      if ((inst->binary[i] == '0' && inst->binary[i + 1] == '1'))
        return (1);
      else if ((inst->binary[i] == '1' && inst->binary[i + 1] == '1'))
        return (11);
      else if ((inst->binary[i] == '1') && (inst->binary[i + 1] == '0'))
        return (10);
      else if ((inst->binary[i] ==  '0') && (inst->binary[i + 1] == '0'))
	return (0);
      i = i + 2;
    }
  return (-1);
}

void		read_binary(t_champ champ, t_instruc *inst)
{
  unsigned char		hexa;
  char		*s;

  read(champ.fd, &hexa, 1);
  inst->binary = my_convert_to_base(hexa, "01");
}

void             read_instruction(t_champ champ, t_instruc *inst)
{
  char		*s;
  int		num;

  num = 0;
  s = NULL;
  read(champ.fd, &(inst->mnemo), 1);
  s = my_convert_to_base(inst->mnemo, "0123456789");
  num = my_getnbr_base(s, "0123456789");
  inst->num = num;
  free(s);
}

t_instruc      *parse_file(t_champ champ)
{
  t_instruc	*inst;
  int		i;

  i = 0;
  inst = NULL;
  inst = malloc(sizeof(t_instruc));
  inst->binary = NULL;
  read_instruction(champ, inst);
  if ((inst->num != 1) && (inst->num != 16)
      && (inst->num != 15) && (inst->num != 13))
    read_binary(champ, inst);
  return (inst);
}
