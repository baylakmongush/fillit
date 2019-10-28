/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:53:57 by npetrell          #+#    #+#             */
/*   Updated: 2019/10/25 22:19:32 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void       ft_create_map(t_dbl_list  **head, int size_map)
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
    while (*head)
    {
        i = -2;
        while ((i += 2) < 8)
        {
         y = (*head)->crd_sharp[i];
         x = (*head)->crd_sharp[i + 1];
         map[x][y] = (*head)->name;
        }
        (*head) = (*head)->next;
    }
    ft_print_map(size_map, map);
}