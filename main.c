/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkina <rkina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:52:44 by rkina             #+#    #+#             */
/*   Updated: 2019/10/28 18:51:42 by rkina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int					ft_combinations(int nbrs_tetra)
{
	int				comb;
	int				n;
	int				k;
	int				n_k;

	n = ft_iterative_factorial(nbrs_tetra);
	k = ft_iterative_factorial(2);
	n_k = ft_iterative_factorial(nbrs_tetra - 2);
	comb = n / (k * n_k);
	return (comb);
}

void				ft_all_overl(int *coord_of_sharp, int min_size, int nbrs_tetra)
{
	int start;

	int i;
	start = 2;
	while (ft_overlay(coord_of_sharp, start))
	{
		coord_of_sharp = ft_move(coord_of_sharp, start, 'x');
		if (ft_check_over_map(coord_of_sharp, start, min_size))
		{
			coord_of_sharp = ft_move_zero_position(coord_of_sharp, start);
			while (ft_overlay(coord_of_sharp, start))
			{
				coord_of_sharp = ft_move(coord_of_sharp, start, 'y');
				if (ft_check_over_map(coord_of_sharp, start, min_size))
				{
					coord_of_sharp = ft_move_zero_position(coord_of_sharp, start);	
					break ;
				}
			}
			break ;
		}
	}
	i = 0;
	printf("After move y ");
	while (i < nbrs_tetra * 8)
	{
		printf("%d", coord_of_sharp[i]);
		i++;
		printf(" ");
	}
	ft_add_to_fin_list(head, coord_of_sharp, nbrs_tetra);
}

int				main(int ac, char **argv)
{
	int			fd;
	int			count_sharp;
	char		*tetra;
	int			*coord_of_sharp;
	t_flist	*head;
	int			min_size;
	int i;

	head = NULL;
	if (ac > 2)
		ft_error_output();
	if (ac == 2)
	{
		fd = open(argv[1], O_RDONLY);
		count_sharp = ft_valid_input(fd);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		tetra = ft_valid_tetra(fd);
		close(fd);
		coord_of_sharp = ft_change_to_coord(tetra, count_sharp);
		ft_create_dbl_list(count_sharp, coord_of_sharp, &head);
		min_size = ft_count_min_s(count_sharp / 4);
		coord_of_sharp = ft_move_zero_position_all(coord_of_sharp, count_sharp);
		i = 0;
		printf("\nBefore swap\n");
		while (i < count_sharp * 2)
		{
			printf("%d", coord_of_sharp[i]);
			i++;
			printf(" ");
		}
		ft_swap_tet(coord_of_sharp, 2, 3);
		i = 0;
		printf("\nAfter swap\n");
		while (i < count_sharp * 2)
		{
			printf("%d", coord_of_sharp[i]);
			i++;
			printf(" ");
		}
		//ft_all_overl(coord_of_sharp, min_size, count_sharp / 4);
		//head->crd_sharp = ft_move(head->crd_sharp, 'x')
	}
}
