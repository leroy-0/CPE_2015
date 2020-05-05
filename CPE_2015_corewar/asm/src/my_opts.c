/*
** my_opts.c for my_opts in /home/tekm/tek1/CPE_2015_corewar/asm
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Sun Mar 27 22:14:52 2016 Tekm
** Last update Sun Mar 27 22:15:12 2016 Tekm
*/

#include "my.h"
#include "asm.h"

void                    opt_ldi_lldi(t_struct_d *data, char type, int cpt_t)
{
  if (type == T_REG && op_tab[data->id].type[cpt_t]&T_REG)
    data->cpt_inst += (T_REG - 1);
  else if (type == T_DIR && op_tab[data->id].type[cpt_t]&T_DIR)
    data->cpt_inst += (T_DIR - 1);
  else if (type == T_IND && op_tab[data->id].type[cpt_t]&T_IND)
    data->cpt_inst += (T_DIR - 1);
}

void                    opt_fork_lfork(t_struct_d *data, char type, int cpt_t)
{
  if (type == T_DIR && op_tab[data->id].type[cpt_t]&T_DIR)
    data->cpt_inst += (T_DIR - 1);
  else if (type == T_IND && op_tab[data->id].type[cpt_t]&T_IND)
    data->cpt_inst += (T_IND - 1);
  else if (type == T_REG && op_tab[data->id].type[cpt_t]&T_REG)
    data->cpt_inst += (T_REG - 1);
}

void                    opt_zjmp(t_struct_d *data, char type, int cpt_t)
{
  if (type == T_DIR && op_tab[data->id].type[cpt_t]&T_DIR)
    data->cpt_inst += (T_DIR - 1);
}

void                    opt_sti(t_struct_d *data, char type, int cpt_t)
{
  if (type == T_IND && op_tab[data->id].type[cpt_t]&T_IND)
    data->cpt_inst += (T_DIR - 1);
  else if (type == T_DIR && op_tab[data->id].type[cpt_t]&T_DIR)
    data->cpt_inst += (T_DIR - 1);
}

void                    opt_normal(t_struct_d *data, char type, int cpt_t)
{
  if (type == T_IND && op_tab[data->id].type[cpt_t]&T_IND)
    data->cpt_inst += (IND_SIZE - 1);
  else if (type == T_DIR && op_tab[data->id].type[cpt_t]&T_DIR)
    data->cpt_inst += (DIR_SIZE - 1);
  else if (type == T_REG && op_tab[data->id].type[cpt_t]&T_REG)
    data->cpt_inst += (T_REG - 1);
}
