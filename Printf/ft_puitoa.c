/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:16:00 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 17:17:44 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(int n)
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

int	ft_puitoa(int nbr)
{
	char	*arr;
	long	nb;
	int		len;

	nb = nbr;
	len = ft_len(nbr);
	arr = malloc((len + 1) * sizeof(char));
	if (nbr < 0)
	{
		arr[0] = '-';
		nb = -nb;
	}
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
	return (ft_len(nbr));
}
