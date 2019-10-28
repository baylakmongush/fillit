/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_over.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:51:27 by rkina             #+#    #+#             */
/*   Updated: 2019/10/28 18:57:44 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_overlay(int *coords, int nbr_tet)
{
	int i;
	int z;
	i = 0; 
	z = nbr_tet * 4;
	while (i < nbr_tet * 4 && z < 8 * nbr_tet)
	{
		int j = 0;
		while (j < z)
		{
			if (coords[j] == coords[z] && coords[j + 1] == coords[z + 1])
				return (1);
			j += 2;
		}
		z += 2;
		i++;
	}
	return (0);
}

int		ft_check_over_map(int *crds, int nbrs_tet, int min_size)
{
	int	i;

	i = nbrs_tet * 4;
	while (i < nbrs_tet * 8)
	{
		if (crds[i] > min_size || crds[i + 1] > min_size)
			return (1);
		i++;
	}
	return (0);
}
