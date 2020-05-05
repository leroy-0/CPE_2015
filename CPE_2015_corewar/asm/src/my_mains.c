/*
** my_mains.c for my_mains in /home/tekm/tek1/CPE_2015_corewar/asm
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Sun Mar 27 22:34:45 2016 Tekm
** Last update Thu Mar 31 12:18:34 2016 Tekm
*/

#include "my.h"
#include "op.h"
#include "asm.h"

void                    fill_parameters(t_struct_d *data, char *str, int cpt)
{
  char                  *tmp;

  cpt = 0;
  tmp = malloc(sizeof(char) * my_strlen(str) + 1);
  while (str[cpt] && str[cpt] != LABEL_CHAR && str[0] != COMMENT_CHAR
         && str[cpt] != DIRECT_CHAR && str[cpt] != SEPARATOR_CHAR)
    cpt++;
  if (str[cpt] == LABEL_CHAR && str[0] != COMMENT_CHAR
      && str[cpt] != DIRECT_CHAR && str[cpt] != SEPARATOR_CHAR)
    main_while(data, str, tmp, cpt);
  else
    main_while2(data, str, cpt);
}

void                    check_label(t_struct_d *data, char *str)
{
  int                   cpt;

  cpt = 0;
  while (str[cpt] && str[cpt] != LABEL_CHAR && str[cpt] != ' ')
    cpt++;
  if (str[cpt] == LABEL_CHAR)
    {
      data->label[data->lines] = malloc(sizeof(char) * my_strlen(str) + 1);
      data->label[data->lines] =
        my_strncpy(data->label[data->lines], str, cpt);
    }
}

void                    get_values(char *str, char *path,
                                   header_t *header, t_struct_d *data)
{
  int                   cpt;

  (void)path;
  cpt = 0;
  if (str && my_strncmp(str, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0)
    fill_header_prog(header, str, cpt);
  if (str &&
      my_strncmp(str, COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING)) == 0)
    fill_comment(header, str, cpt);
  check_label(data, str);
  fill_parameters(data, str, cpt);
}

void                    fill_zero(t_struct_d *data, header_t header)
{
  int                   cpt;

  (void)header;
  cpt = 0;
  data->cpt_inst = 0;
  header.prog_size = 0;
  while (cpt < MEM_SIZE)
    data->inst[cpt++] = (int)0;
  cpt = 0;
  while (cpt < MEM_SIZE)
    data->saveinst[cpt++] = (int)0;
  cpt = 0;
  while (cpt < MEM_SIZE)
    data->label[cpt++] = "\0";
  cpt = 0;
  while (cpt < PROG_NAME_LENGTH + 1)
    cpt++;
  while (cpt < PROG_NAME_LENGTH + 1)
    header.prog_name[cpt++] = (int)0;
  cpt = 0;
  while (cpt < COMMENT_LENGTH + 1)
    header.comment[cpt++] = (int)0;
}

int                     init_all2(t_struct_d *data, int fd)
{
  data->name[my_strlen(data->name) - 1] = '\0';
  data->path = malloc(sizeof(char) * my_strlen(data->name) + 5);
  data->path = my_strcpy(data->path, data->name);
  data->path = my_strcat(data->path, "cor");
  if ((data->fd =
       open(data->path, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU)) == -1)
    {
      write(1, "ERROR: File couldn't be created\n", 31);
      exit(1);
    }
  return (fd);
}
