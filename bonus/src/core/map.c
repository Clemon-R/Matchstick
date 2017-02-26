/*
** map.c for default in /home/raphael.goulmot/rendu/CPE_2016_matchstick
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Feb 21 19:06:31 2017 Raphaël Goulmot
** Last update Tue Feb 21 19:45:23 2017 Raphaël Goulmot
*/

#include "map.h"
#include <stdlib.h>

char	**create_map(int size)
{
  char	**map;
  int	length;
  int	y;
  int	x;

  y = 0;
  map = malloc(sizeof(char *) * (size + 1));
  while (y++ < size && !(x = 0))
    {
      length = 1 + (y - 1) * 2;
      map[y - 1] = malloc(sizeof(char) * (length + 1));
      while (x++ < length)
	map[y - 1][x - 1] = '|';
      map[y - 1][x - 1] =  '\0';
    }
  map[y - 1] = '\0';
  return (map);
}
