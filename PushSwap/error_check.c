/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:25:09 by ksng              #+#    #+#             */
/*   Updated: 2025/07/29 17:03:37 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atol(char *str)
{
	long	res;
	int		i;
	int		neg;

	i = 0;
	neg = 1;
	res = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		res = (res * 10) + (str[i] - '0');
		if ((res * neg) > 2147483647 || (res * neg) < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

static int	is_out_int(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (ft_atol(arr[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	not_int(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != 0)
	{
		j = 0;
		if (arr[i][j] == '-' || arr[i][j] == '+')
		{
			j++;
			if (arr[i][j] == '\0')
				return (1);
		}
		while (arr[i][j] != '\0')
		{
			if (!(ft_isdigit((arr[i][j]))))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_dup(char **arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_error(char **arr, int len)
{
	if (is_dup(arr, len) == 1 || not_int(arr) == 1 || is_out_int(arr, len) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
