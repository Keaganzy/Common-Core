/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puunitoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:17:59 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 17:19:04 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_puunitoa(unsigned int n)
{
	char			*arr;
	unsigned int	nb;
	unsigned int	len;

	nb = n;
	len = ft_len(nb);
	arr = malloc((len + 1) * sizeof(char));
	if (nb == 0)
		arr[0] = '0';
	arr[len] = '\0';
	while (nb != 0)
	{
		arr[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	write(1, arr, ft_strlen(arr));
	free (arr);
	return (ft_len(n));
}
