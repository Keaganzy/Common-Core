/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:14:02 by ksng              #+#    #+#             */
/*   Updated: 2025/07/30 16:01:17 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_stk
{
	struct s_stk	*next;
	struct s_stk	*prev;
	int				content;
	int				idx;
	int				op_cost;
	int				r_op_cost;
	int				which;
	int				prefer;
	int				is_low;
}	t_stk;

int		is_error(char **arr, int len);
void	sort_stk(char **arr, t_stk **hdtla, t_stk **hdtlb, int count);
void	stk_push(t_stk **to_push, t_stk **rec, int printflag);
int		lstsize(t_stk *lst);
void	stk_rot(t_stk **head, int reverse, int printflag);
void	stk_swap(t_stk **head, int printflag);
void	update_cost(t_stk **hd_a, t_stk **hd_b);
void	free_arr(char **arr);
char	**process_argv(char **argv, int *argc);
int		process_argv_count(char ***split_arr);
char	**process_argv_fillarr(char ***split_arr, int count);
void	free_split_arr(int i, char ***split_arr);
void	free_stk(t_stk **hdtl);
void	free_arr(char **arr);
int		fill_stk(t_stk **hdtla, char **arr, int len);
void	turk(t_stk **hd_a, t_stk **hd_b);
int		sorted_stack(t_stk **stack, int size);
int		sortedness(t_stk **small_ptr, t_stk **hd_a);
void	fill_stk_b(t_stk **hd_a, t_stk **hd_b);
void	do_lowest_op_back(t_stk **hd_b, t_stk **hd_a);
int		cost_calculation(t_stk *stk_a, t_stk *stk_b);
int		refac_find_low(t_stk *a, t_stk *b, t_stk **lowa, t_stk **lowb);
int		do_rot_or_rrot(t_stk **stack, t_stk *lowest, int printflag);
t_stk	*sml_ptr(t_stk **stack);
t_stk	*big_ptr(t_stk **stack);
int		big(t_stk **stack);
int		small(t_stk **stack);
int		size_of_stk(t_stk **stack);
void	do_three_stk(t_stk **stack);

#endif