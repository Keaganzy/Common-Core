/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:09:43 by ksng              #+#    #+#             */
/*   Updated: 2025/07/29 13:20:58 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	small(t_stk **stack)
{
	t_stk	*temp;
	int		small;

	small = 100000000;
	temp = *stack;
	while (1)
	{
		if (temp->idx < small)
		{
			small = temp->idx;
		}
		if (temp->next == *stack)
			break ;
		temp = temp->next;
	}
	return (small);
}

int	big(t_stk **stack)
{
	t_stk	*temp;
	int		big;

	big = 0;
	temp = *stack;
	while (1)
	{
		if (temp->idx > big)
		{
			big = temp->idx;
		}
		if (temp->next == *stack)
			break ;
		temp = temp->next;
	}
	return (big);
}

t_stk	*big_ptr(t_stk **stack)
{
	t_stk	*temp;
	t_stk	*biggest;
	int		big;

	big = 0;
	temp = *stack;
	while (1)
	{
		if (temp->idx > big)
		{
			big = temp->idx;
			biggest = temp;
		}
		if (temp->next == *stack)
			break ;
		temp = temp->next;
	}
	return (biggest);
}

t_stk	*sml_ptr(t_stk **stack)
{
	t_stk	*temp;
	t_stk	*smallest;
	int		small;

	small = 1000000000;
	temp = *stack;
	while (1)
	{
		if (temp->idx < small)
		{
			small = temp->idx;
			smallest = temp;
		}
		if (temp->next == *stack)
			break ;
		temp = temp->next;
	}
	return (smallest);
}

int	size_of_stk(t_stk **stack)
{
	t_stk	*temp;
	int		count;

	count = 0;
	if (!stack || !*stack)
		return (count);
	temp = *stack;
	while (1)
	{
		count++;
		if (temp->next == *stack)
			break ;
		temp = temp->next;
	}
	return (count);
}
