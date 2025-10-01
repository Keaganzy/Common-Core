/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stk_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:56:13 by ksng              #+#    #+#             */
/*   Updated: 2025/07/29 13:13:18 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stk(t_stk **hdtl)
{
	t_stk	*current;
	t_stk	*next;
	t_stk	*check;

	if (!hdtl || !*hdtl)
		return ;
	current = *hdtl;
	check = *hdtl;
	while (current->next != check)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
	*hdtl = NULL;
}

static void	stkadd_back(t_stk **lst, t_stk *new)
{
	t_stk	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->next = *lst;
		(*lst)->prev = *lst;
		return ;
	}
	temp = *lst;
	while (temp->next != *lst)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->prev = temp;
	new->next = *lst;
	(*lst)->prev = new;
}

t_stk	*new_node(char *str)
{
	t_stk	*new;

	new = malloc(sizeof(t_stk));
	if (!new)
		return (NULL);
	new->content = ft_atoi(str);
	new->next = NULL;
	new->prev = NULL;
	new->op_cost = 0;
	new->r_op_cost = 0;
	new->which = 1;
	new->prefer = 0;
	new->is_low = 0;
	return (new);
}

int	fill_stk(t_stk **hdtla, char **arr, int len)
{
	int		i;
	t_stk	*node;

	i = 0;
	while (i < len)
	{
		node = new_node(arr[i]);
		if (node == NULL)
		{
			free_stk(hdtla);
			return (1);
		}
		stkadd_back(hdtla, node);
		i++;
	}
	return (0);
}
