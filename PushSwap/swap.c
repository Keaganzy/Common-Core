/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:57:36 by ksng              #+#    #+#             */
/*   Updated: 2025/07/29 21:36:57 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_swap(t_stk **head, int printflag)
{
	t_stk	*temp;

	if (!head || lstsize(*head) < 2)
		return ;
	temp = *head;
	if ((*head)->which == 1)
	{
		if (printflag)
			ft_printf("sa\n");
	}
	else
	{
		if (printflag)
			ft_printf("sb\n");
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	temp = temp->next;
	(*head)->prev = temp;
	(*head)->next = temp->next;
	(*head)->next->prev = *head;
	temp->next = *head;
	*head = temp;
}
