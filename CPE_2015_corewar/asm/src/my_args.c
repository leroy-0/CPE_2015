/*
** my_args.c for my_args in /home/tekm/tek1/CPE_2015_corewar/asm
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Sun Mar 27 22:25:20 2016 Tekm
** Last update Sun Mar 27 22:37:53 2016 Tekm
*/

#include "my.h"
#include "op.h"
#include "asm.h"

void                    convert_arg(t_struct_d *data)
{
  char                  *tmp;
  int                   cpt_a;

  cpt_a = 0;
  tmp = malloc(sizeof(char) * 10);
  while (data->cmds[cpt_a])
    {
      if (data->cmds[cpt_a][0] == 'r' || data->cmds[cpt_a][0] == 'R')
        check_opt(data, cpt_a, 0, tmp, T_REG);
      else if (data->cmds[cpt_a][0] == '%')
        check_opt(data, cpt_a, 0, tmp, T_DIR);
      else if (data->cmds[cpt_a][0] >= '0' && data->cmds[cpt_a][0] <= '9')
        check_opt(data, cpt_a, -1, tmp, T_IND);
      cpt_a++;
    }
}

char                    *fill_bin(t_struct_d *data, char *bin, int cpt, int i)
{
  while (data->cmds[cpt])
    {
      if (data->cmds[cpt][0] == 'r')
        {
          bin[i++] = '0';
          bin[i++] = '1';
        }
      else if (data->cmds[cpt][0] == '%')
        {
          bin[i++] = '1';
          bin[i++] = '0';
        }
      else
        {
          bin[i++] = '1';
          bin[i++] = '1';
        }
      cpt++;
    }
  while (i < 8)
    bin[i++] = '0';
  bin[i] = '\0';
  return (bin);
}

void                    my_binaries(t_struct_d *data)
{
  char          *bin;
  int           cpt;
  int           i;

  i = 0;
  cpt = 0;
  if ((bin = malloc(sizeof(char) * 9)) == NULL)
    exit(1);
  bin = fill_bin(data, bin, cpt, i);
  data->inst[data->cpt_inst] = binary(my_getnbr(bin));
  data->cpt_inst++;
}

int                     check_arg(char *action, char **args)
{
  int                   i;
  int                   nb_args;

  i = 0;
  nb_args = 0;
  while (my_strcmp(action, op_tab[i].mnemonique) != 0)
    i++;
  if (my_strcmp(action, op_tab[i].mnemonique) == 0)
    nb_args = (int)op_tab[i].nbr_args;
  i = 0;
  while (args[i] != NULL)
    i++;
  if (i > nb_args)
    {
      my_putstr("Error : ");
      my_putstr(action);
      my_putstr(" takes ");
      my_put_nbr(nb_args);
      my_putstr(" arguments\n");
      exit(1);
    }
  return (0);
}

void                    get_cmds(t_struct_d *data, char *str,
				 char *action, int cpt)
{
  int                   cpt_c;

  cpt_c = 0;
  cpt = my_strlen(action) + 1;
  while (str[cpt])
    {
      cpt_c = 0;
      data->cmds[data->cpt_c] = malloc(sizeof(char) * my_strlen(str));
      while (str[cpt] && str[cpt] != SEPARATOR_CHAR)
        {
          data->cmds[data->cpt_c][cpt_c] = str[cpt];
          cpt_c++;
          cpt++;
        }
      data->cmds[data->cpt_c][cpt_c] = '\0';
      data->cmds[data->cpt_c] = epur_str(data->cmds[data->cpt_c]);
      data->cpt_c++;
      if (str[cpt])
        cpt++;
    }
  data->cmds[data->cpt_c] = NULL;
}
