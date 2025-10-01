/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puhexnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:19:22 by ksng              #+#    #+#             */
/*   Updated: 2025/07/29 14:45:59 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puhexnbr(unsigned int n, char c)
{
	char	*hex;
	int		count;

	count = 0;
	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	if (n < 16)
	{
		ft_puchar(hex[n]);
		count++;
	}
	else
	{
		count += ft_puhexnbr(n / 16, c);
		count += ft_puhexnbr(n % 16, c);
	}
	return (count);
}
