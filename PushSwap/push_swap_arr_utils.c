/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_arr_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:58:56 by ksng              #+#    #+#             */
/*   Updated: 2025/07/29 17:03:56 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split_arr(int i, char ***split_arr)
{
	int	j;

	while (i >= 0)
	{
		j = 0;
		while (split_arr[i][j])
		{
			free(split_arr[i][j]);
			j++;
		}
		free(split_arr[i]);
		i--;
	}
}

char	**process_argv_fillarr(char ***split_arr, int count)
{
	int		i;
	int		j;
	int		index;
	char	**arr;

	i = 0;
	index = 0;
	arr = malloc(sizeof(*arr) * (count + 1));
	if (!arr)
		return (0);
	while (split_arr[i])
	{
		j = 0;
		while (split_arr[i][j])
		{
			arr[index] = split_arr[i][j];
			index++;
			j++;
		}
		free(split_arr[i]);
		i++;
	}
	arr[count] = 0;
	return (arr);
}

int	process_argv_count(char ***split_arr)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (split_arr[i])
	{
		j = 0;
		while (split_arr[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	**process_argv(char **argv, int *argc)
{
	char	***split_arr;
	char	**arr;
	int		i;

	i = 0;
	split_arr = malloc(sizeof(*split_arr) * (*argc));
	if (!split_arr)
		return (0);
	split_arr[*argc - 1] = 0;
	while (++i < *argc)
	{
		split_arr[i - 1] = ft_split(argv[i], ' ');
		if (!split_arr[i - 1] || !*split_arr[i - 1])
		{
			if (split_arr[i - 1] && !*split_arr[i - 1])
				write(2, "Error\n", 6);
			free_split_arr(i - 1, split_arr);
			free(split_arr);
			return ((char **) 0);
		}
	}
	*argc = process_argv_count(split_arr);
	arr = process_argv_fillarr(split_arr, *argc);
	free(split_arr);
	return (arr);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
}
