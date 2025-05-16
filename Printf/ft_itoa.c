/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:38:46 by ksng              #+#    #+#             */
/*   Updated: 2025/05/16 20:07:16 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_mallocsize(int n, int neg)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (neg + count);
}

static int	ft_absb(int n)
{
	if (n < 0)
	{
		return (n * -1);
	}
	return (n);
}

char	*ft_itoa(int n)
{
	int		neg;
	char	*s;
	int		msize;

	neg = 0;
	if (n < 0)
		neg = 1;
	msize = ft_mallocsize(n, neg);
	s = malloc((msize + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[msize] = '\0';
	if (n == 0)
		s[0] = '0';
	if (neg)
		s[0] = '-';
	while (n)
	{
		s[msize - 1] = ft_absb((n % 10)) + '0';
		n /= 10;
		msize--;
	}
	return (s);
}

/* int	main()
{
	printf("%s\n",ft_itoa(-2147483648));
	printf("%s",ft_itoa(2147483647));
} */