/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:53:57 by npetrell          #+#    #+#             */
/*   Updated: 2019/10/28 19:00:06 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void       ft_print_map(int size_map, char map[size_map][size_map])
{
    int     x;
    int     y;

    x = -1;
    while (++x < size_map)
    {
        y = 0;
        while (y < size_map)
        {
            write(1, &map[x][y], 1);
            y++;
        }
        write(1, "\n", 1);
    }
}

void       ft_create_map(t_flist  *head, int size_map)
{
    char   map[size_map][size_map];
    int    i;
    int    x;
    int    y;

    x = -1;
    while (++x < size_map)
    {
        y = 0;
        while (y < size_map)
            map[x][y++] = '.';
    }
    while (head)
    {
        i = -2;
        while ((i += 2) < 8)
        {
         y = head->crd_sharp[i];
         x = head->crd_sharp[i + 1];
         map[x][y] = head->name;
        }
        head = head->next;
    }
    ft_print_map(size_map, map);
}

void       ft_add_to_fin_list(t_flist **head, int *coord_of_sharp, int nbrs_tetra)
{
    int     i;
    int     j;
    int     remainder;
    t_flist *tmp;
    int     *rmb[8];
    int     count;

    tmp = *head;
    i = 0;
    while (*head)
    {
        i = 0;
        while (i < nbrs_tetra * 8)
        {
            j = 0;
            count = 0;
            while (j < 8)
            {
                remainder = coord_of_sharp[i] - (*head)->crd_sharp[j];
                if (remainder == (coord_of_sharp[i + 1] - (*head)->crd_sharp[j + 1]))
                {
                    count++;
                }
                i++;
                j++;
            }
            if (count == 4)
            {
                j = 0;
                while (j < 8)
                {
                    (*head)->crd_sharp[j] = coord_of_sharp[i];
                    coord_of_sharp[i] = 0;
                    j++;
                    i++;
                }
                break ;
            }
            i++;
        }
        (*head) = (*head)->next;
    }
    ft_create_map(tmp, 3);
}
