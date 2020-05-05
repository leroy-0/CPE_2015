/*
** asm.c for asm in /home/tekm/tek1/CPE_2015_corewar
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Wed Mar 23 14:32:39 2016 Tekm
** Last update Sun Mar 27 22:35:29 2016 Tekm
*/

#include "my.h"
#include "op.h"
#include "asm.h"
#include "get_next_line.h"

int			init_all(t_struct_d *data, char *name)
{
  int			fd;

  data->lines = 0;
  data->cpt_c = 0;
  data->turn = 0;
  if ((data->label = malloc(sizeof(char *) * MEM_SIZE)) == NULL)
    exit(1);
  if ((data->saveinst = malloc(sizeof(char) * MEM_SIZE)) == NULL)
    exit(1);
  if ((data->name = malloc(sizeof(char) * my_strlen(name) + 1)) == NULL)
    exit(1);
  if ((data->name = my_strcpy(data->name, name)) == NULL)
    exit(1);
  if ((data->cmds = malloc(sizeof(data->cmds) * 50)) == NULL)
    exit(1);
  if ((fd = open(data->name, O_RDONLY)) == -1)
    {
      my_putstr("Error : Couldn't open file '");
      my_putstr(data->name);
      my_putstr("'\n");
      exit(1);
    }
  return (init_all2(data, fd));
}

void			write_values(t_struct_d *data, header_t header)
{
  char			*tmp;
  int			cpt;

  cpt = 0;
  if ((tmp = malloc(sizeof(char) * data->cpt_inst)) == NULL)
    exit(1);
  while (cpt < data->cpt_inst)
    {
      tmp[cpt] = data->inst[cpt];
      cpt++;
    }
  header.prog_size =  data->cpt_inst;
  header.prog_size = ((header.prog_size>>24)&0xff)
    | ((header.prog_size<<8)&0xff0000)
    | ((header.prog_size>>8)&0xff00)
    | ((header.prog_size<<24)&0xff000000);
  write(data->fd, &header, sizeof(header));
  write(data->fd, tmp, sizeof(char) * (data->cpt_inst));
  close(data->fd);
}

void			my_asm2(t_struct_d data, header_t header, int fd)
{
  char			*str;
  int			cpt;

  cpt = 0;
  data.turn = 1;
  data.lines = 0;
  data.cpt_c = 0;
  data.cpt_inst = 0;
  while (cpt < MEM_SIZE)
    data.inst[cpt++] = (int)0;
  cpt = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      data.lines++;
      if (epur_str(str) != NULL)
	get_values(epur_str(str), data.path, &header, &data);
    }
  write_values(&data, header);
}

void			my_asm(char *name)
{
  t_struct_d		data;
  header_t		header;
  char			*str;
  int			fd;

  fd = init_all(&data, name);
  fill_zero(&data, header);
  while ((str = get_next_line(fd)) != NULL)
    {
      data.lines++;
      if (epur_str(str) != NULL)
	get_values(epur_str(str), data.path, &header, &data);
    }
  if ((fd = open(name, O_RDONLY)) == -1)
    exit(1);
  my_asm2(data, header, fd);
}

int			main(int ac, char **av)
{
  if (ac == 2)
    my_asm(av[1]);
  else
    {
      my_putstr("Usage : ");
      my_putstr(av[0]);
      my_putstr(" file_name(.s)\n");
    }
  return (0);
}
