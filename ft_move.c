/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:33:42 by npetrell          #+#    #+#             */
/*   Updated: 2019/10/25 23:01:25 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_move(int *coord_of_tet, int nbr_tet, char x_y)
{
	int	i;

	i = (x_y == 'x') ? (0 + nbr_tet * 4) : (nbr_tet * 4 + 1);
	while (i < nbr_tet * 4 * 2)
	{
		coord_of_tet[i] += 1;
		i += 2;
	}
	return (coord_of_tet);
}
