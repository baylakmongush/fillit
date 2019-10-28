/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_to_coord.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:31:26 by npetrell          #+#    #+#             */
/*   Updated: 2019/10/28 18:50:05 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			*ft_change_to_coord(char *tetra, int count_sharp) // зафришить
{
	int		*coord_of_sharp;
	int		i;
	int		j;

	coord_of_sharp = (int*)malloc(sizeof(int) * count_sharp * 2);
	ft_bzero(coord_of_sharp, count_sharp * 2 * 4);
	i = 0;
	j = 0;
	while (*tetra)
	{
		if (*tetra == '#')
		{
			coord_of_sharp[j] = i % 4;
			coord_of_sharp[j + 1] = i / 4;
			j += 2;
		}
		i++;
		tetra++;
		if (i % 16 == 0)
			i = 0;
	}
	return (coord_of_sharp);
}

int				*ft_move_zero_position(int *coord, int nbr_tet)
{
	int			i;
	int			min_x;
	int			min_y;

	i = 2 + nbr_tet * 4;
	min_x = coord[nbr_tet * 4];
	min_y = coord[nbr_tet * 4 + 1];
	while (i < nbr_tet * 8)
	{
		if (min_x > coord[i])
			min_x = coord[i];
		if (min_y > coord[i + 1])
			min_y = coord[i + 1];
		i += 2;
	}
	i = nbr_tet * 4;
	while (i < nbr_tet * 8)
	{
		coord[i] = coord[i] - min_x;
		coord[i + 1] = coord[i + 1] - min_y;
		i += 2;
	}
	return (coord);
}

int		*ft_swap_tet(int *coord, int a, int b)
{
	int tmp;
	int i;
	int j;

	i = (a - 1) * 8;
	j = (b - 1) * 8;
	while (i < a * 8)
	{
		tmp = coord[i];
		coord[i] = coord[j];
		coord[j] = tmp;
		j++;
		i++;
	}
	return (coord);
}