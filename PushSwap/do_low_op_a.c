/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_low_op_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:14:51 by ksng              #+#    #+#             */
/*   Updated: 2025/07/29 21:35:37 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_rr_rrr(int *a, int *b)
{
	if (*a > 0 && *b > 0)
	{
		while (*a > 0 && *b > 0)
		{
			ft_printf("rr\n");
			*a -= 1;
			*b -= 1;
		}
	}
	if (*a < 0 && *b < 0)
	{
		while (*a < 0 && *b < 0)
		{
			ft_printf("rrr\n");
			*a += 1;
			*b += 1;
		}
	}
}

void	print_rb_rrb(int *b)
{
	while (*b)
	{
		if (*b > 0)
		{
			ft_printf("rb\n");
			*b -= 1;
		}
		else if (*b < 0)
		{
			ft_printf("rrb\n");
			*b += 1;
		}
	}
}

void	print_ra_rra(int *a)
{
	while (*a)
	{
		if (*a > 0)
		{
			ft_printf("ra\n");
			*a -= 1;
		}
		else if (*a < 0)
		{
			ft_printf("rra\n");
			*a += 1;
		}
	}
}

void	find_lowest_back(t_stk **hd_a, t_stk **hd_b, t_stk **lowa, t_stk **lowb)
{
	int		lowest;
	t_stk	*tempa;
	t_stk	*tempb;

	lowest = 10000000;
	tempb = *hd_b;
	while (1)
	{
		tempa = *hd_a;
		while (1)
		{
			if ((tempb->idx < tempa->idx && tempb->idx > tempa->prev->idx)
				&& cost_calculation(tempa, tempb) < lowest)
				lowest = refac_find_low(tempa, tempb, lowa, lowb);
			else if ((tempb->idx > big(&tempa) || tempb->idx < small(&tempa))
				&& cost_calculation(sml_ptr(&tempa), tempb) < lowest)
				lowest = refac_find_low(sml_ptr(&tempa), tempb, lowa, lowb);
			if (tempa->next == *hd_a || lowest == 0)
				break ;
			tempa = tempa->next;
		}
		if (tempb->next == *hd_b || lowest == 0)
			break ;
		tempb = tempb->next;
	}
}

void	do_lowest_op_back(t_stk **hd_b, t_stk **hd_a)
{
	t_stk	*lowest_a;
	t_stk	*lowest_b;
	int		a;
	int		b;

	find_lowest_back(hd_a, hd_b, &lowest_a, &lowest_b);
	lowest_a->is_low = 1;
	lowest_b->is_low = 1;
	a = do_rot_or_rrot(hd_a, lowest_a, 0);
	b = do_rot_or_rrot(hd_b, lowest_b, 0);
	lowest_a->is_low = 0;
	lowest_b->is_low = 0;
	print_rr_rrr(&a, &b);
	print_ra_rra(&a);
	print_rb_rrb(&b);
	stk_push(hd_b, hd_a, 1);
}
