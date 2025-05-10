/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:23:57 by ksng              #+#    #+#             */
/*   Updated: 2025/05/10 16:44:42 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *temp;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	temp = new;
	while (lst != 0)
	{
		temp->content = f(lst->content);
		if (lst->next != 0)
		{
			temp->next = malloc(sizeof(t_list));
			temp = temp->next;
			if (!temp)
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
			lst = lst->next;
		}
	}
	return (new);
}
