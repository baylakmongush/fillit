/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:05:56 by rkina             #+#    #+#             */
/*   Updated: 2019/11/09 00:04:56 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_valid_input(const int fd)
{
	char	*line;
	int		count;
	int		j;
	int		i;
	int		p;

	count = 0;
	i = 0;
	p = 0;
	while (get_next_line(fd, &line) > 0)
	{
		count++;
		if (count % 5 != 0)
		{
			ft_strlen(line) != 4 ? ft_error_output() : line;
			j = -1;
			while (line[++j])
			{
				line[j] == '.' || line[j] == '#' ? line[j] : ft_error_output();
				line[j] == '#' ? i++ : p++;
			}
		}
		if (count % 5 == 0)
			(p + i) % 16 != 0 ? ft_error_output() : p;
		free(line);
	}
	(count - 4) % 5 != 0 ? ft_error_output() : count;
	p == 0 ? ft_error_output() : i;
	i % 4 != 0 ? ft_error_output() : i;
	count + 1 > 130 ? ft_error_output() : count;
	return (i);
}
