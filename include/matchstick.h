/*
** matchstick.h for default in /home/raphael.goulmot/rendu/CPE_2016_matchstick
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Feb 21 19:01:29 2017 Raphaël Goulmot
** Last update Tue Feb 21 20:33:50 2017 Raphaël Goulmot
*/

#ifndef MATCHSTICK_H_
# define MATCHSTICK_H_

typedef	struct	s_world
{
  char	**map;
  int	size;
  int	matches;
}		t_world;

char	end_game(t_world *);
char	play_game(t_world *);
char	matchstick(int, int);

#endif
