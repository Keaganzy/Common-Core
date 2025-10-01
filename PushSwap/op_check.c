/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:00:54 by ksng              #+#    #+#             */
/*   Updated: 2025/07/29 21:37:39 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_stack(t_stk **stack, int size)
{
	t_stk	*smallest;
	t_stk	*biggest;

	if (!stack || !*stack)
		return (0);
	if (size == 1)
		return (1);
	smallest = *stack;
	biggest = (*stack)->prev;
	if (smallest->idx != 0 || biggest->idx != size - 1)
		return (0);
	while ((smallest->idx) + 1 == smallest->next->idx)
	{
		if (smallest->next == biggest)
			return (1);
		smallest = smallest->next;
	}
	return (0);
}

int	sortedness(t_stk **small_ptr, t_stk **hd_a)
{
	t_stk	*smallest;
	t_stk	*biggest;

	*small_ptr = *hd_a;
	if (!small_ptr || !*small_ptr)
		return (0);
	biggest = big_ptr(small_ptr);
	smallest = sml_ptr(small_ptr);
	*small_ptr = smallest;
	if (smallest->prev->idx == biggest->idx)
	{
		while (smallest->idx < smallest->next->idx)
		{
			if (smallest->next->idx == biggest->idx)
				return (1);
			smallest = smallest->next;
		}
	}
	return (0);
}

int	do_rot_or_rrot(t_stk **stack, t_stk *lowest, int printflag)
{
	int	i;

	i = 0;
	if ((lowest->prefer == 1 && lowest->is_low == 1)
		|| (lowest->op_cost <= lowest->r_op_cost))
	{
		while (i < lowest->op_cost)
		{
			stk_rot(stack, 0, printflag);
			i++;
		}
		return (i);
	}
	else if ((lowest->prefer == -1 && lowest->is_low == 1)
		|| (lowest->r_op_cost < lowest->op_cost))
	{
		while (i < lowest->r_op_cost)
		{
			stk_rot(stack, 1, printflag);
			i++;
		}
		return (i * -1);
	}
	return (0);
}

void	do_three_stk(t_stk **stack)
{
	if ((*stack)->idx == small(stack))
	{
		stk_rot(stack, 0, 1);
		stk_swap(stack, 1);
		stk_rot(stack, 1, 1);
	}
	else if ((*stack)->idx == big(stack))
	{
		if ((*stack)->next->idx == small(stack))
			stk_rot(stack, 0, 1);
		else
		{
			stk_swap(stack, 1);
			stk_rot(stack, 1, 1);
		}
	}
	else
	{
		if ((*stack)->next->idx == big(stack))
			stk_rot(stack, 1, 1);
		else
			stk_swap(stack, 1);
	}
}
