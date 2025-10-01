/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:07:30 by ksng              #+#    #+#             */
/*   Updated: 2025/05/12 17:44:31 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	negflag;
	int	answer;

	i = 0;
	negflag = 1;
	answer = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == 32)
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negflag = -1;
		i++;
	}
	while (('0' <= nptr[i] && nptr[i] <= '9') && nptr[i] != '\0')
	{
		answer *= 10;
		answer += nptr[i] - '0';
		i++;
	}
	return (answer * negflag);
}

/* #include <stdio.h>
#include <stdlib.h>

int	main()
{
	printf("### Function: atoi ###");
	printf("output: %d\n",ft_atoi("-123#3"));
	printf("expected: %d\n\n",atoi("-123#3"));

	printf("output: %d\n",ft_atoi("  123@2"));
	printf("expected: %d\n\n",atoi("  123@2"));

	printf("output: %d\n",ft_atoi("  +  -12+3!1"));
	printf("expected: %d\n\n",atoi("   + -12+3!1"));

	printf("output: %d\n",ft_atoi("+123!1"));
	printf("expected: %d\n\n",atoi("+123!1"));

	printf("output: %d\n",ft_atoi("-+123a1"));
	printf("expected: %d\n\n",atoi("-+123a1"));

	printf("output: %d\n",ft_atoi("+-123a1"));
	printf("expected: %d\n\n",atoi("+-123a1"));

	printf("output: %d\n",ft_atoi("   -1-23a1"));
	printf("expected: %d\n\n",atoi("   -1-23a1"));

	printf("output: %d\n",ft_atoi(""));
	printf("expected: %d\n\n",atoi(""));

	printf("output: %d\n",ft_atoi("  -+  "));
	printf("expected: %d\n\n",atoi("  -+  "));

	printf("output: %d\n",ft_atoi("   +"));
	printf("expected: %d\n\n",atoi("   +"));
} */