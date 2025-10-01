/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_cal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:13:04 by ksng              #+#    #+#             */
/*   Updated: 2025/07/29 13:23:25 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_minus(int a, int b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

void	set_pref(t_stk *stk_a, t_stk *stk_b, int pref_a, int pref_b)
{
	stk_a->prefer = pref_a;
	stk_b->prefer = pref_b;
}

int	cost_calculation(t_stk *stk_a, t_stk *stk_b)
{
	int	lowest;

	lowest = 100000000;
	if (abs_minus(stk_a->op_cost, stk_b->op_cost) < lowest)
	{
		lowest = abs_minus(stk_a->op_cost, stk_b->op_cost);
		set_pref(stk_a, stk_b, 1, 1);
	}
	if (stk_a->op_cost + stk_b->r_op_cost < lowest)
	{
		lowest = stk_a->op_cost + stk_b->r_op_cost;
		set_pref(stk_a, stk_b, 1, -1);
	}
	if (stk_a->r_op_cost + stk_b->op_cost < lowest)
	{
		lowest = stk_a->r_op_cost + stk_b->op_cost;
		set_pref(stk_a, stk_b, -1, 1);
	}
	if (abs_minus(stk_a->r_op_cost, stk_b->r_op_cost) < lowest)
	{
		lowest = abs_minus(stk_a->r_op_cost, stk_b->r_op_cost);
		set_pref(stk_a, stk_b, -1, -1);
	}
	return (lowest);
}
