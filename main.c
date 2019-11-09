/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:52:44 by rkina             #+#    #+#             */
/*   Updated: 2019/11/09 16:12:05 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_output(void)
{
	ft_putstr("usage: ./fillit target_file\n");
	exit(0);
}

int				main(int ac, char **argv)
{
	int			fd_and_minsize;
	int			count_sharp;
	char		*tetra;
	int			*coords_of_sharp;
	t_flist		*head;

	head = NULL;
	if (ac != 2)
		ft_output();
	if (ac == 2)
	{
		fd_and_minsize = open(argv[1], O_RDONLY);
		count_sharp = ft_valid_input(fd_and_minsize);
		close(fd_and_minsize);
		fd_and_minsize = open(argv[1], O_RDONLY);
		tetra = ft_valid_tetra(fd_and_minsize);
		close(fd_and_minsize);
		coords_of_sharp = ft_change_to_coord(tetra, count_sharp);
		free(tetra);
		ft_create_flist(count_sharp, coords_of_sharp, &head);
		fd_and_minsize = ft_count_min_s(count_sharp / 4);
		coords_of_sharp = zero_position_all(coords_of_sharp, count_sharp);
		ft_fillit(&head, coords_of_sharp, fd_and_minsize, count_sharp / 4);
		free(coords_of_sharp);
	}
}
