/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_p_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:00:03 by ksng              #+#    #+#             */
/*   Updated: 2025/05/20 16:57:11 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
}

void	ft_puhexanum(char *str, unsigned long addr, int count)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;
	if (addr == 0)
		str[i++] = '0';
	else
	{
		while (count > 0)
		{
			str[i++] = hex[addr % 16];
			addr /= 16;
			count--;
		}
	}
	str[i] = '\0';
}

void	ft_reversestr(char *str)
{
	int		start;
	int		end;
	char	temp;

	if (!str)
		return ;
	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
}
