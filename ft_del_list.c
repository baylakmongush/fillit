/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:36:30 by npetrell          #+#    #+#             */
/*   Updated: 2019/11/09 13:42:51 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_clear_list(t_flist **head)
{
	t_flist *curr;
	t_flist	*temp;

	if (*head != NULL)
	{
		curr = (*head)->next;
		while (curr != NULL && curr != *head)
		{
			temp = curr;
			curr = curr->next;
			free(temp);
		}
		free(*head);
		*head = NULL;
	}
}
