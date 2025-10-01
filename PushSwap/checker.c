/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:59:06 by ksng              #+#    #+#             */
/*   Updated: 2025/07/30 14:21:17 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_operation(char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0 || ft_strncmp(str, "sb\n", 3) == 0)
		return (1);
	if (ft_strncmp(str, "ss\n", 3) == 0 || ft_strncmp(str, "pa\n", 3) == 0)
		return (1);
	if (ft_strncmp(str, "pb\n", 3) == 0 || ft_strncmp(str, "ra\n", 3) == 0)
		return (1);
	if (ft_strncmp(str, "rb\n", 3) == 0 || ft_strncmp(str, "rr\n", 3) == 0)
		return (1);
	if (ft_strncmp(str, "rra\n", 4) == 0 || ft_strncmp(str, "rrb\n", 4) == 0)
		return (1);
	if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (1);
	return (0);
}

static void	handle_r_rr_ops(char *str, t_stk **hd_a, t_stk **hd_b)
{
	if (ft_strncmp(str, "ra\n", 3) == 0)
		stk_rot(hd_a, 0, 0);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		stk_rot(hd_b, 0, 0);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
	{
		stk_rot(hd_a, 0, 0);
		stk_rot(hd_b, 0, 0);
	}
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		stk_rot(hd_a, 1, 0);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		stk_rot(hd_b, 1, 0);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
	{
		stk_rot(hd_a, 1, 0);
		stk_rot(hd_b, 1, 0);
	}
}

static void	handle_push_swap_ops(char *str, t_stk **hd_a, t_stk **hd_b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		stk_swap(hd_a, 0);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		stk_swap(hd_b, 0);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
	{
		stk_swap(hd_a, 0);
		stk_swap(hd_b, 0);
	}
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		stk_push(hd_b, hd_a, 0);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		stk_push(hd_a, hd_b, 0);
}

int	receive_ops(char *str, t_stk **hd_a, t_stk **hd_b, int *op_res)
{
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			return (*op_res = 0);
		if (!is_valid_operation(str))
		{
			write(2, "Error\n", 6);
			free(str);
			return (*op_res = 1);
		}
		handle_r_rr_ops(str, hd_a, hd_b);
		handle_push_swap_ops(str, hd_a, hd_b);
		free(str);
	}
	return (*op_res = 0);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**arr;
	t_stk	*hd_a;
	t_stk	*hd_b;
	int		op_res;

	hd_a = 0;
	hd_b = 0;
	str = 0;
	arr = process_argv(argv, &argc);
	if (!arr)
		return (1);
	if (argc < 1 || is_error(arr, argc) == 1)
		return (free_arr(arr), free(arr), 1);
	if (fill_stk(&hd_a, arr, argc))
		return (free_arr(arr), free(arr), 1);
	sort_stk(arr, &hd_a, &hd_b, argc);
	receive_ops(str, &hd_a, &hd_b, &op_res);
	if (sorted_stack(&hd_a, size_of_stk(&hd_a)) && hd_b == NULL && op_res == 0)
		ft_printf("OK\n");
	else if (!op_res)
		ft_printf("KO\n");
	(free_stk(&hd_a), free_stk(&hd_b));
	(free(hd_a), free(hd_b));
	return (1);
}
