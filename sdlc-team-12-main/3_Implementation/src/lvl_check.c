/**
 * @file lvl_check.c
 * @author Vishal Singh (vishal.singh@ltts.com)
 * @brief This function sets the level according to player input
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "matrix.h"
/**
 * @brief If player choose medium level
 * 
 * @param s 
 * @param list 
 * @param i 
 * @param y 
 * @return int 
 */
int	lvl_medium(t_struct *s, t_list *list, int i, int y)
{
  while (y < YMAX)
    i ^= l_allum(list, y++);
  y = YMIN;
  if (list == list->next)
    return (marienbad_del(s, list, 1, list->y));
  if (calc_nb_lines(list, list, 0) == 1)
    return (marienbad_del(s, list, l_allum(list, list->y) - 1, list->y));
  if (i != 2)
    i /= 2;
  if (i > 0)
    while (y < YMAX)
      if (l_allum(list, y++) >= i)
        return (marienbad_del(s, list, i, y - 1));
  y = YMIN;
  while (y < YMAX)
    if (l_allum(list, y++) > 0)
      return (marienbad_del(s, list, 1, y - 1));
  return (0);
}
/**
 * @brief If player select easy level
 * 
 * @param s 
 * @param list 
 * @param i 
 * @param y 
 * @return int 
 */
int	lvl_easy(t_struct *s, t_list *list, int i, int y)
{
  while (y < YMAX)
    i ^= l_allum(list, y++);
  y = YMIN;
  if (list == list->next)
    return (marienbad_del(s, list, 1, list->y));
  if (calc_nb_lines(list, list, 0) == 1)
    i -= 2;
  if (i > 0)
    while (y < YMAX)
      if (l_allum(list, y++) >= i)
        return (marienbad_del(s, list, i, y - 1));
  y = YMIN;
  while (y < YMAX)
    if (l_allum(list, y++) > 0)
      return (marienbad_del(s, list, 1, y - 1));
  return (0);
}

int	lvl_check(t_struct *s, t_list *list)
{
  if (s->lvl == 0)
    return (lvl_easy(s, list, 0, YMIN));
  if (s->lvl == 1)
    return (lvl_medium(s, list, 0, YMIN));
  return (marienbad(s, list, 0, YMIN));
}
