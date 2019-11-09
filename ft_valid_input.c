/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:05:56 by rkina             #+#    #+#             */
/*   Updated: 2019/11/09 16:00:30 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_valid_input(const int fd)
{
	char	*line;
	int		p[4];

	p[0] = 0;
	p[2] = 0;
	p[3] = 0;
	while (get_next_line(fd, &line) > 0)
	{
		p[0]++;
		if (p[0] % 5 != 0)
		{
			ft_strlen(line) != 4 ? ft_err() : line;
			p[1] = -1;
			while (line[++p[1]])
			{
				line[p[1]] == '.' || line[p[1]] == '#' ? line[p[1]] : ft_err();
				line[p[1]] == '#' ? p[2]++ : p[3]++;
			}
		}
		p[0] % 5 == 0 && (p[2] + p[3]) % 16 != 0 ? ft_err() : p[3];
		free(line);
	}
	(p[0] - 4) % 5 != 0 || p[3] == 0 || p[2] % 4 != 0 ||
	p[0] + 1 > 130 ? ft_err() : p[0];
	return (p[2]);
}
