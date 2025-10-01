/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:33:59 by ksng              #+#    #+#             */
/*   Updated: 2025/07/29 13:02:41 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_arr(int *num_arr, int count)
{
	int	i;
	int	temp;
	int	flag;

	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i < count)
		{
			if (i + 1 < count)
			{
				if ((num_arr)[i] > (num_arr)[i + 1])
				{
					temp = (num_arr)[i + 1];
					(num_arr)[i + 1] = (num_arr)[i];
					(num_arr)[i] = temp;
					flag = 1;
				}
			}
			i++;
		}
	}
}

static void	fill_stk_index(int *num_arr, int count, t_stk **hdtla)
{
	int		i;
	int		j;
	t_stk	*templist;

	i = 0;
	while (i < count)
	{
		templist = (*hdtla);
		j = 0;
		while (j < count)
		{
			if (templist->content == num_arr[i])
			{
				templist->idx = i;
				break ;
			}
			templist = templist->next;
			j++;
		}
		i++;
	}
}

void	sort_stk(char **arr, t_stk **hdtla, t_stk **hdtlb, int count)
{
	int	i;
	int	*num_arr;

	i = 0;
	num_arr = malloc(sizeof(int) * count);
	if (!num_arr)
	{
		free(arr);
		exit(1);
	}
	while (i < count)
	{
		num_arr[i] = ft_atoi(arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
	sort_arr(num_arr, count);
	fill_stk_index(num_arr, count, hdtla);
	(void)hdtla;
	(void)hdtlb;
	free(num_arr);
}
