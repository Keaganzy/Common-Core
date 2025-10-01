/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:02:55 by ksng              #+#    #+#             */
/*   Updated: 2025/07/29 21:36:30 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stk	*lstadd_front(t_stk **lst, t_stk *new)
{
	if (!lst || !new)
		return (0);
	if (!(*lst))
	{
		*lst = new;
		(*lst)->next = new;
		(*lst)->prev = new;
		return (*lst);
	}
	new->next = *lst;
	new->prev = (*lst)->prev;
	(*lst)->prev = new;
	new->prev->next = new;
	*lst = new;
	return (*lst);
}

int	lstsize(t_stk *lst)
{
	int		count;
	t_stk	*temp;

	if (!lst)
		return (0);
	count = 1;
	temp = lst;
	while (lst->next != temp)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

static void	push_target(t_stk **to_push, int printflag)
{
	if ((*to_push)->which == 1)
	{
		if (printflag)
			ft_printf("pb\n");
		(*to_push)->which *= -1;
	}
	else
	{
		if (printflag)
			ft_printf("pa\n");
		(*to_push)->which *= -1;
	}
}

void	stk_push(t_stk **to_push, t_stk **rec, int printflag)
{
	t_stk	*temp;

	if (lstsize(*to_push) == 0)
		return ;
	else if (lstsize(*to_push) == 1)
	{
		push_target(to_push, printflag);
		*rec = lstadd_front(rec, *to_push);
		*to_push = NULL;
	}
	else
	{
		temp = *to_push;
		temp->next->prev = (*to_push)->prev;
		temp->prev->next = (*to_push)->next;
		temp = temp->next;
		push_target(to_push, printflag);
		*rec = lstadd_front(rec, *to_push);
		*to_push = temp;
	}
}
