/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_link_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:28:31 by npetrell          #+#    #+#             */
/*   Updated: 2019/10/25 22:19:31 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void         add_dbl_link_list(t_dbl_list **head, char name_tetra)
{
    t_dbl_list	*new_node;

    new_node = (t_dbl_list*)malloc(sizeof(t_dbl_list));
    new_node->name = name_tetra;
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head != NULL)
        (*head)->prev = new_node;
    *head = new_node;
}

int				*ft_move_zero_position_all(int *coord, int len)
{
	int			i;
	int			j;
	int			min_x;
	int			min_y;

	j = -8;
	while ((j += 8) < len)
	{
		i = 0;
		min_x = coord[j];
		min_y = coord[j + 1];
		while ((i += 2) < 8)
		{
			min_x = (min_x > coord[i + j]) ? coord[i + j] : min_x;
			min_y = (min_y > coord[i + j + 1]) ? coord[i + j + 1] : min_y;
		}
		i = -2;
		while ((i += 2) < 8)
		{
			coord[i + j] = coord[i + j] - min_x;
			coord[i + j + 1] = coord[i + j + 1] - min_y;
		}
	}
	return (coord);
}

void			ft_create_dbl_list(int count_sharp, int *coord_of_sharp,
 t_dbl_list **head)
{
	int	    	count_tetra;
	int	    	i;
	char	    name_tetra;

	name_tetra = 'A';
	count_tetra = count_sharp / 4;
	coord_of_sharp = ft_move_zero_position_all(coord_of_sharp, count_sharp * 2);
	while (count_tetra-- > 0 && head)
	{
		i = 0;
		add_dbl_link_list(head, name_tetra);
		while (i < 8)
		{
			(*head)->crd_sharp[i]= *coord_of_sharp;
			coord_of_sharp++;
			i++;
		}
		name_tetra++;
	}
}