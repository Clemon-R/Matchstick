/*
** player.c for default in /home/raphael.goulmot/rendu/CPE_2016_matchstick
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Feb 21 19:36:34 2017 Raphaël Goulmot
** Last update Tue Feb 21 21:21:58 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "matchstick.h"
#include "map.h"
#include "display.h"
#include "get_next_line.h"

char	get_error(char *arg, int nbr, t_world world, char line)
{
  if (!arg || my_strlen(arg) <= 0 || !my_str_isnumeric(arg))
    {
      my_putstr_err("Error: invalid input (positive number expected)\n");
      return (1);
    }
  else if (nbr <= 0 || (!line && nbr > world.size)
   || (line && (nbr > my_strlen(world.map[line - 1]) || nbr > world.matches)))
    {
      if (!line)
	my_putstr_err("Error: this line is out of range\n");
      else if (nbr > world.matches)
	{
	  my_putstr_err("Error: you cannot remove more than ");
	  my_put_nbr(world.matches);
	  my_putstr_err(" matches per turn\n");
	}
      else
	my_putstr_err(nbr <= 0
	   ? "Error: you have to remove at least one match\n"
		      : "Error: not enough matches on this line\n");
      return (1);
    }
  return (0);
}

void	remove_stick(char p, int line, int stick, t_world *world)
{
  int	size;

  size = my_strlen(world->map[line - 1]) - 1;
  if (p)
    my_putstr("Player");
  else
    my_putstr("AI");
  my_putstr("u removed ");
  my_put_nbr(stick);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
  while (stick)
    {
      world->map[line - 1][size--] = '\0';
      stick--;
    }
}

void	player_turn(t_world *world)
{
  int	line;
  int	stick;
  char	*arg;

  line = 0;
  stick = 0;
  my_putstr("\nYour turn:\n");
  while (line <= 0 || stick <= 0)
    {
      my_putstr("Line: ");
      arg = get_next_line(0);
      if (!get_error(arg, (line = my_getnbr(arg)), *world, 0))
	{
	  my_putstr("Matches: ");
	  arg = get_next_line(0);
	  stick = get_error(arg, (stick = my_getnbr(arg)), *world, line)
	    ? 0 : stick;
	}
    }
  remove_stick(1, line, stick, world);
  display_map(world);
}
