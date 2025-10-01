/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stk_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:12:01 by ksng              #+#    #+#             */
/*   Updated: 2025/07/29 21:33:09 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	seg_count(int size)
{
	int	seg;

	seg = 0;
	if (size <= 100 && size > 11)
		seg = 4;
	else if (size <= 10)
		seg = 1;
	else
		seg = 8;
	return (seg);
}

static int	check_early_exit(t_stk **hd_a, t_stk *temp)
{
	if (sortedness(&temp, hd_a) == 1)
		return (1);
	if (size_of_stk(hd_a) == 3 && sortedness(&temp, hd_a) == 0)
	{
		do_three_stk(hd_a);
		return (1);
	}
	return (0);
}

static void	process_element(t_stk **hd_a, t_stk **hd_b, int seg_limit,
				int next_seg_limit)
{
	if ((*hd_a)->idx <= seg_limit)
		stk_push(hd_a, hd_b, 1);
	else if ((*hd_a)->idx >= seg_limit && (*hd_a)->idx <= next_seg_limit)
	{
		stk_push(hd_a, hd_b, 1);
		stk_rot(hd_b, 0, 1);
	}
	else
		stk_rot(hd_a, 0, 1);
}

void	fill_stk_b(t_stk **hd_a, t_stk **hd_b)
{
	int		seg;
	int		i;
	t_stk	*temp;
	int		size;
	int		tempsize;

	i = 1;
	temp = NULL;
	size = size_of_stk(hd_a);
	seg = seg_count(size);
	while (i <= seg)
	{
		tempsize = size_of_stk(hd_a);
		while (tempsize--)
		{
			if (check_early_exit(hd_a, temp))
				return ;
			process_element(hd_a, hd_b, i * (size / seg),
				(i + 1) * ((size / seg) + (size % seg)));
		}
		i = i + 2;
	}
}
