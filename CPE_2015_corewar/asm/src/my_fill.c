/*
** my_fill.c for my_fill in /home/tekm/tek1/CPE_2015_corewar/asm
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Sun Mar 27 22:29:28 2016 Tekm
** Last update Sun Mar 27 22:54:52 2016 Tekm
*/

#include "op.h"
#include "my.h"
#include "asm.h"

void                    get_arg(char *str, t_struct_d *data, char *action)
{
  int                   cpt;

  cpt = 0;
  data->nbinst = data->cpt_inst;
  get_cmds(data, str, action, cpt);
  check_arg(action, data->cmds);
  if (my_strcmp(action, "live") != 0 && my_strcmp(action, "zjmp") != 0
      && my_strcmp(action, "fork") != 0 && my_strcmp(action, "lfork") != 0)
    my_binaries(data);
  data->cpt_c = 0;
  convert_arg(data);
  data->nbinst = data->cpt_inst - data->nbinst + 1;
  data->saveinst[data->lines] = data->nbinst;
}

void                    fill_header_prog(header_t *header, char *str, int cpt)
{
  header->magic = COREWAR_EXEC_MAGIC;
  header->magic = ((header->magic>>24)&0xff)
    | ((header->magic<<8)&0xff0000)
    | ((header->magic>>8)&0xff00)
    | ((header->magic<<24)&0xff000000);
  cpt = my_strlen(NAME_CMD_STRING) + 2;
  while (str[cpt + 1])
    {
      header->prog_name[cpt - my_strlen(NAME_CMD_STRING) - 2] = str[cpt];
      cpt++;
    }
  header->prog_name[cpt - my_strlen(NAME_CMD_STRING) - 2] = '\0';
}

void                    fill_comment(header_t *header, char *str, int cpt)
{
  cpt = my_strlen(COMMENT_CMD_STRING) + 2;
  while (str[cpt + 1])
    {
      header->comment[cpt - my_strlen(COMMENT_CMD_STRING) - 2] = str[cpt];
      cpt++;
    }
  header->comment[cpt - my_strlen(COMMENT_CMD_STRING) - 2] = '\0';
}

void                    main_while(t_struct_d *data, char *str,
				   char *tmp, int cpt)
{
  int           x;

  x = 0;
  cpt++;
  while (str[cpt])
    {
      tmp[x] = str[cpt];
      cpt++;
      x++;
    }
  tmp[x] = '\0';
  tmp = epur_str(tmp);
  cpt = 0;
  while (op_tab[cpt].mnemonique)
    {
      if (tmp && my_strncmp(tmp, op_tab[cpt].mnemonique,
                            my_strlen(op_tab[cpt].mnemonique)) == 0)
        {
          data->id = cpt;
          data->inst[data->cpt_inst] = data->id + 1;
          data->cpt_inst++;
          get_arg(tmp, data, op_tab[cpt].mnemonique);
        }
      cpt++;
    }
}

void                    main_while2(t_struct_d *data, char *str, int cpt)
{
  cpt = 0;
  while (op_tab[cpt].mnemonique)
    {
      if (str && my_strncmp(str, op_tab[cpt].mnemonique,
                            my_strlen(op_tab[cpt].mnemonique)) == 0)
        {
          data->id = cpt;
          data->inst[data->cpt_inst] = data->id + 1;
          data->cpt_inst++;
          get_arg(str, data, op_tab[cpt].mnemonique);
        }
      cpt++;
    }
}

