/*
** my_params.c for my_params in /home/tekm/tek1/CPE_2015_corewar/asm
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Sun Mar 27 22:18:36 2016 Tekm
** Last update Thu Apr  7 14:45:52 2016 Tekm
*/

#include "op.h"
#include "my.h"
#include "asm.h"

void                    get_labelsup(t_struct_d *data, int y, int x, char *tmp)
{
  char          *tmp_t;

  data->nbinst = 0;
  y = data->lines;
  while (y != x)
    {
      data->nbinst += data->saveinst[y];
      y++;
    }
  tmp = hexa(data->nbinst, 16, "0123456789ABCDEF");
  if (my_strlen(tmp) < 3)
    {
      data->inst[data->cpt_inst - 1] = (int)0;
      data->inst[data->cpt_inst] = hexa_int(tmp, my_strlen(tmp));
    }
  else
    {
      if ((tmp_t = malloc(sizeof(char) * 3)) == NULL)
        exit(1);
      tmp_t[0] = tmp[2];
      tmp_t[1] = tmp[3];
      tmp_t[2] = tmp[2] = '\0';
      data->inst[data->cpt_inst - 1] = hexa_int(tmp, my_strlen(tmp));
      data->inst[data->cpt_inst] = hexa_int(tmp_t, my_strlen(tmp_t));
    }
}

void                    get_labelinf(t_struct_d *data, int y, int x, char *tmp)
{
  char          *tmp_t;

  y = data->lines;
  data->nbinst = -data->saveinst[y];
  while (y >= x)
    {
      data->nbinst += data->saveinst[y];
      y--;
    }
  data->nbinst = 65536 - data->nbinst;
  tmp = hexa(data->nbinst, 16, "0123456789ABCDEF");
  if ((tmp_t = malloc(sizeof(char) * 3)) == NULL)
    exit(1);
  tmp_t[0] = tmp[2];
  tmp_t[1] = tmp[3];
  tmp_t[2] = '\0';
  tmp[2] = '\0';
  data->inst[data->cpt_inst - 1] = hexa_int(tmp, my_strlen(tmp));
  data->inst[data->cpt_inst] = hexa_int(tmp_t, my_strlen(tmp_t));
}

void                    get_label(t_struct_d *data, int cpt_a, int cpt)
{
  char          *tmp;
  int           y;
  int           x;

  x = 0;
  y = 0;
  if ((tmp = malloc(sizeof(char) * my_strlen(data->cmds[cpt_a]) + 1)) == NULL)
    exit(1);
  cpt++;
  while (data->cmds[cpt_a][cpt])
    {
      tmp[x] = data->cmds[cpt_a][cpt];
      cpt++;
      x++;
    }
  tmp[x] = '\0';
  while (x < MEM_SIZE && my_strcmp(tmp, data->label[x]) != 0)
    x++;
  if (tmp && data->label[x] && my_strcmp(tmp, data->label[x]) == 0)
    {
      if (x > data->lines)
        get_labelsup(data, y, x, tmp);
      else
        get_labelinf(data, y, x, tmp);
    }
}

void                    get_params(t_struct_d *data,
				   int cpt, int cpt_a)
{
  char				*tmp;
  int                           cpt_x;

  cpt_x = 0;
  if ((tmp = malloc(sizeof(char) *
		    (my_strlen(data->cmds[cpt_a]) + 1))) == NULL)
    exit(1);
  if (data->cmds[cpt_a][cpt] != LABEL_CHAR)
    {
      while (data->cmds[cpt_a][cpt])
        {
          tmp[cpt_x] = data->cmds[cpt_a][cpt];
          cpt_x++;
          cpt++;
        }
      tmp[cpt_x] = '\0';
      data->inst[data->cpt_inst] = my_getnbr(tmp);
      data->cpt_inst++;
    }
  else
    {
      if (data->turn == 1)
        get_label(data, cpt_a, cpt);
      data->cpt_inst++;
    }
}

void                    check_opt(t_struct_d *data, int cpt_a, int cpt,
                                  char *tmp, char type)
{
  static int                    cpt_t = 0;

  cpt++;
  (void)tmp;
  if (my_strcmp(op_tab[data->id].mnemonique, "sti") == 0 && cpt_t != 0)
    opt_sti(data, type, cpt_t);
  else if (my_strcmp(op_tab[data->id].mnemonique, "zjmp") == 0)
    opt_zjmp(data, type, cpt_t);
  else if ((my_strcmp(op_tab[data->id].mnemonique, "ldi") == 0
            && cpt_t != 2) ||
           (my_strcmp(op_tab[data->id].mnemonique, "lldi") == 0
            && cpt_t != 2))
    opt_ldi_lldi(data, type, cpt_t);
  else if (my_strcmp(op_tab[data->id].mnemonique, "fork") == 0 ||
           my_strcmp(op_tab[data->id].mnemonique, "lfork") == 0)
    opt_fork_lfork(data, type, cpt_t);
  else
    opt_normal(data, type, cpt_t);
  if (op_tab[data->id].nbr_args == cpt_t + 1)
    cpt_t = 0;
  else
    cpt_t++;
  get_params(data, cpt, cpt_a);
}
