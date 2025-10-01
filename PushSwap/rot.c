/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:58:00 by ksng              #+#    #+#             */
/*   Updated: 2025/07/29 16:37:06 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_rot(t_stk **head, int reverse, int printflag)
{
	if (!head || lstsize(*head) == 0)
		return ;
	if (reverse)
	{
		if (printflag)
		{
			if ((*head)->which == 1)
				ft_printf("rra\n");
			else
				ft_printf("rrb\n");
		}
		*head = (*head)->prev;
	}
	else
	{
		if (printflag)
		{
			if ((*head)->which == 1)
				ft_printf("ra\n");
			else
				ft_printf("rb\n");
		}
		*head = (*head)->next;
	}
}
