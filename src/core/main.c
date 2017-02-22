/*
** main.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 29 16:01:44 2016 Raphaël Goulmot
** Last update Tue Feb 21 21:05:29 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "matchstick.h"
#include <time.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
  if (argc != 3 || !my_str_isnumeric(argv[1]) || !my_str_isnumeric(argv[2]))
    {
      my_putstr_err("ERROR : Error parameters !\n");
      return (84);
    }
  srand(time(0));
  return (matchstick(my_getnbr(argv[1]), my_getnbr(argv[2])));
}
