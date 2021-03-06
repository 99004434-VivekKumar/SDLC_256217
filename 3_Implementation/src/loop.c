
/**
 * @file loop.c
 * @brief function definition for Game process 
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */




#include <time.h>
#include "matrix.h"

int	check_if_some_selectted(t_list *tmp, t_list *list)
{
  while (list->next != tmp)
    {
      if (list->select == 1)
	return (2);
      list = list->next;
    }
  if (list->select == 1)
    return (2);
  return (0);
}

int	selectt_pos(t_struct *s, t_list *list, int *lock)
{
  while (list->pos != 2)
    list = list->next;
  if (list->select == 0)
    list->select = 1;
  else
    list->select = 0;
  move_left_right(s, list, KEY_RIGHT);
  *lock = check_if_some_selectted(list, list);
  return (0);
}

int	delete_selectted(t_struct *s, t_list **list, int *lock)
{
  int	i;

  if (*lock == 0)
    return (0);
  i = list_size(*list) + 1;
  while (i-- != 0)
    if ((*list)->select == 1)
      delete_list(list);
    else
      *list = (*list)->next;
  *lock = 0;
  if (*list == NULL)
    {
      *lock = 3;
      return (0);
    }
  (*list)->pos = 1;
  print_list(s, *list, 0);
  return (0);
}

int		load_game(t_struct *s, t_list *list)
{
  time_t	tim;

  tim = time(NULL);
  s->turn = 1;
  print_list(s, list, 0);
  if (s->mode == 0)
    player_vs_player(s, list, 0, 0);
  if (s->mode == 1)
    player_vs_bot(s, list, 0, 0);
  if (s->mode == 2)
    bot_vs_bot(s, list, 0);
  return (win_display(s, tim));
}
