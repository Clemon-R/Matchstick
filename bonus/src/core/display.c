/*
** display.c for default in /home/raphael.goulmot/rendu/CPE_2016_matchstick
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Feb 21 18:56:12 2017 Raphaël Goulmot
** Last update Tue Feb 21 20:39:57 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "matchstick.h"

void	display_border(t_world *world)
{
  int	size;
  int	i;

  i = 0;
  size = world->size * 2 + 1;
  while (i++ < size)
    my_putchar('*');
  my_putchar('\n');
}

void	display_map(t_world *world)
{
  int	y;
  int	x;
  int	space;
  int	max;

  y = 0;
  space = ((world->size - 1) * 2 + 1) / 2;
  display_border(world);
  while (world->map[y++] && !(x = 0))
    {
      my_putchar('*');
      while (x++ < space)
	my_putchar(' ');
      x = 0;
      while (world->map[y - 1][x] && ++x)
	my_putchar(world->map[y - 1][x - 1]);
      max = ((world->size - 1) * 2 + 1) - (space + x);
      x = 0;
      while (x++ < max)
	my_putchar(' ');
      my_putchar('*');
      my_putchar('\n');
      space--;
    }
  display_border(world);
}
