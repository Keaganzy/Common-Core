/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:11:06 by ksng              #+#    #+#             */
/*   Updated: 2025/08/01 04:40:59 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk(t_stk **hd_a, t_stk **hd_b)
{
	t_stk	*small_ptr;

	if (sorted_stack(hd_a, size_of_stk(hd_a)) == 1)
		return ;
	else if (!*hd_b && size_of_stk(hd_a) == 3)
	{
		do_three_stk(hd_a);
		return ;
	}
	else if (!*hd_b && size_of_stk(hd_a) == 2)
	{
		stk_swap(hd_a, 1);
		return ;
	}
	fill_stk_b(hd_a, hd_b);
	while (sorted_stack(hd_a, size_of_stk(hd_a) + size_of_stk(hd_b)) == 0)
	{
		update_cost(hd_a, hd_b);
		if (sortedness(&small_ptr, hd_a) && *hd_b == NULL)
		{
			do_rot_or_rrot(hd_a, small_ptr, 1);
			break ;
		}
		do_lowest_op_back(hd_b, hd_a);
	}
}

int	main(int argc, char **argv)
{
	char	**arr;
	t_stk	*hdtla;
	t_stk	*hdtlb;

	hdtla = 0;
	hdtlb = 0;
	arr = process_argv(argv, &argc);
	if (!arr)
		return (1);
	if (argc < 1 || is_error(arr, argc) == 1)
		return (free_arr(arr), free(arr), 1);
	if (fill_stk(&hdtla, arr, argc))
		return (free_arr(arr), free(arr), 1);
	sort_stk(arr, &hdtla, &hdtlb, argc);
	turk(&hdtla, &hdtlb);
	free_stk(&hdtla);
	free_stk(&hdtlb);
	free(hdtla);
	free(hdtlb);
}

	//(free(hdtlb), free(hdtla));
	//setvbuf(stdout, NULL, _IONBF, 0); //remove
	// printList(hd_a);
	// printList(hd_b);
// 	void	printList(t_stk** head)  
// {
//     t_stk* current = *head;
//     printf("Linked list: \n");
//     while (current != NULL) 
// 	{
//         //printf("content-->%d \n", current->content);
// 		printf("idx-->%d \n", current->idx);
// 		// printf("op-->%d\n", current->op_cost);
// 		// printf("r_op-->%d\n", current->r_op_cost);
// 		// printf("r_op-->%d\n", current->r_op_cost);
//         current = current->next;
// 		if (current == *head)
// 		{
// 			break;
// 		}
//     }
//     printf("NULL\n");
// }
