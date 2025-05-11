/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:34:54 by ksng              #+#    #+#             */
/*   Updated: 2025/05/10 15:56:53 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return;
	t_list *temp;
	temp = *lst;
	while (temp->next != 0)
	{
		temp = temp->next;
	}
	temp->next = new;
}
