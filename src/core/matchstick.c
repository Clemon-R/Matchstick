/*
** matchstick.c for default in /home/raphael.goulmot/rendu/CPE_2016_matchstick
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Feb 21 19:00:07 2017 Raphaël Goulmot
** Last update Sun Feb 26 02:50:10 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "matchstick.h"
#include "display.h"
#include "map.h"
#include "player.h"
#include "get_next_line.h"
#include "AI.h"

char	end_game(t_world *world)
{
  int	y;
  int	x;

  y = 0;
  while (world->map[y++] && !(x = 0))
    while (world->map[y - 1][x++])
      if (world->map[y - 1][x - 1] == '|')
	return (0);
  return (1);
}

char	play_game(t_world *world)
{
  int	winner;

  winner = 1;
  display_map(world);
  while (!end_game(world))
    {
      player_turn(world);
      if (!end_game(world))
	AI_turn(world);
      else
	winner = 2;
    }
  my_putstr(winner == 1 ? "I lost... snif... but I'll get you next time!!\n"
	: "You lost, too bad...\n");
  return (winner);
}

char	matchstick(int arg1, int arg2)
{
  t_world	world;

  if (arg1 <= 0 || arg2 <= 0)
    {
      my_putstr_err("ERROR : Only number above 0 !\n");
      return (84);
    }
  world.map = create_map(arg1);
  world.size = arg1;
  world.matches = arg2;
  return (play_game(&world));
}
