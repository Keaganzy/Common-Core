/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:25:53 by ksng              #+#    #+#             */
/*   Updated: 2025/05/10 15:51:22 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int count;
	
	if (!lst)
		return (NULL);
	count = 0;
	while (lst != 0)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
