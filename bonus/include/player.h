/*
** player.h for default in /home/raphael.goulmot/rendu/CPE_2016_matchstick
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Feb 21 19:37:30 2017 Raphaël Goulmot
** Last update Sun Feb 26 21:58:09 2017 Raphaël Goulmot
*/

#ifndef PLAYER_H_
# define PLAYER_H_

# include "matchstick.h"

char	get_error(char *, int, t_world, char);
void	remove_stick(char, int, int, t_world *);
void	player_turn(t_world *);

#endif
