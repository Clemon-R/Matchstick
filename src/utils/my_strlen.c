/*
** my_strlen.c for default in /home/raphael.goulmot/default_struct
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Dec 20 15:36:56 2016 Raphaël Goulmot
** Last update Wed Feb 15 17:25:06 2017 Raphaël Goulmot
*/

#include "utils.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] && ++i);
  return (i);
}
