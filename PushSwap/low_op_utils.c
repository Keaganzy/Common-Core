/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_op_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:16:36 by ksng              #+#    #+#             */
/*   Updated: 2025/07/29 13:29:13 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_prefer(t_stk **stack)
{
	t_stk	*temp;

	if (!stack || !*stack)
		return ;
	(*stack)->prefer = 0;
	if (*stack == (*stack)->next)
		return ;
	temp = (*stack)->next;
	while (temp != *stack)
	{
		temp->prefer = 0;
		temp = temp->next;
	}
}

static void	update_stack_cost(t_stk **stack)
{
	t_stk	*temp;
	int		cost;

	cost = 1;
	if (!stack || !*stack)
		return ;
	(*stack)->op_cost = 0;
	(*stack)->r_op_cost = 0;
	if (*stack == (*stack)->next)
		return ;
	temp = (*stack)->next;
	while (temp != *stack)
	{
		temp->op_cost = cost;
		cost++;
		temp = temp->next;
	}
	temp = (*stack)->prev;
	cost = 1;
	while (temp != *stack)
	{
		temp->r_op_cost = cost;
		cost++;
		temp = temp->prev;
	}
}

void	update_cost(t_stk **hd_a, t_stk **hd_b)
{
	if (*hd_a)
	{
		update_stack_cost(hd_a);
		update_prefer(hd_a);
	}
	if (*hd_b)
	{
		update_stack_cost(hd_b);
		update_prefer(hd_b);
	}
}

int	refac_find_low(t_stk *a, t_stk *b, t_stk **lowa, t_stk **lowb)
{
	*lowa = a;
	*lowb = b;
	return (cost_calculation(a, b));
}
