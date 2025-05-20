/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:53:53 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 16:56:52 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_counthex(unsigned long addr)
{
	int	count;

	count = 0;
	if (addr == 0)
		return (1);
	while (addr > 0)
	{
		addr /= 16;
		count++;
	}
	return (count);
}
