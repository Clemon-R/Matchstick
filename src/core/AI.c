/*
** AI.c for default in /home/raphael.goulmot/rendu/CPE_2016_matchstick
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Feb 21 20:44:36 2017 Raphaël Goulmot
** Last update Tue Feb 21 21:36:56 2017 Raphaël Goulmot
*/

#include "player.h"
#include "utils.h"
#include "matchstick.h"
#include "display.h"
#include <stdlib.h>

int	get_random(int a, int b)
{
  return (rand()%(b - a + 1) + a);
}

int	get_total(t_world *world)
{
  int	y;
  int	x;
  int	count;

  count = 0;
  y = 0;
  while (world->map[y++] && !(x = 0))
    while (world->map[y - 1][x++])
      count++;
  return (count);
}

int	get_line(t_world *world, int line)
{
  int	x;
  int	count;

  count = 0;
  while (world->map[line - 1][x++])
    count++;
  return (count);
}

void	check_stick(t_world *world, int *line, int *stick)
{
  int	total;
  int	t_line;

  total = get_total(world);
  t_line = get_line(world, *line);
  if (total == t_line && world->matches <= total)
    *stick = total < world->matches ? total - 1 : world->matches - 1;
  else if (total == t_line && total - world->matches == 1)
    *stick = world->matches;
  else if (total - t_line == 1 && t_line <= world->matches)
    *stick = t_line;
  else if (total == t_line && total - world->matches <= world->matches)
    *stick = 1;
  *stick = *stick <= 0 ? 1 : *stick;
}
  
void	AI_turn(t_world *world)
{
  int	line;
  int	stick;
  int	size;

  my_putstr("\nAI's turn...\n");
  line = 0;
  while (!line)
    {
      line = get_random(1, world->size);
      size = my_strlen(world->map[line - 1]);
      if (!size)
	line = 0;
    }
  stick = get_random(1, size > world->matches ? world->matches : size);
  check_stick(world, &line, &stick);
  remove_stick(0, line, stick, world);
  display_map(world);
}
