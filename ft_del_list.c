/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetrell <npetrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:36:30 by npetrell          #+#    #+#             */
/*   Updated: 2019/11/08 15:35:59 by npetrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		dltnode(t_flist **head, t_flist *del)
{
	if (*head == NULL || del == NULL)
		return ;
	if (*head == del)
		*head = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
	return ;
}

void		ft_del_list(t_flist **head)
{
/*	while (*head)
	{
		dltnode(head, *head);
		*head = (*head)->next;
	}*/
	dltnode(head, *head);
	dltnode(head, (*head)->next);
	dltnode(head, (*head)->next);
}
