/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pupointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:13:19 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 17:30:32 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puhexapointer(unsigned long nbr)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (nbr < 16)
	{
		ft_puchar(hex[nbr]);
		count++;
	}
	else
	{
		count += ft_puhexapointer(nbr / 16);
		count += ft_puhexapointer(nbr % 16);
	}
	return (count);
}

int	ft_pupointer(unsigned long addr)
{
	if (addr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_puchar('0');
	ft_puchar('x');
	return (ft_puhexapointer(addr) + 2);
}
