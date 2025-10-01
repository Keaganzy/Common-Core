/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_monster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:42:20 by ksng              #+#    #+#             */
/*   Updated: 2025/08/03 23:20:36 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_monster(t_map *map)
{
	int	y;
	int	x;
	int	m;

	m = 0;
	y = 0;
	x = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			if (map->arr[y][x] == 'X')
				m++;
			x++;
		}
		x = 0;
		y++;
	}
	return (m);
}

void	alloc_monster(t_map *map)
{
	int	y;
	int	x;
	int	m;

	m = 0;
	y = 0;
	x = 0;
	while (y < map->y)
	{
		while (x < map->x && m < map->monster.num)
		{
			if (map->arr[y][x] == 'X')
			{
				map->monster.arr[0][m] = y;
				map->monster.arr[1][m] = x;
				m++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	find_monster(t_map *map)
{
	map->monster.num = count_monster(map);
	if (map->monster.num <= 0)
		return ;
	map->monster.arr = malloc(sizeof(int **) * 3);
	map->monster.arr[0] = malloc(sizeof(int *) * map->monster.num + 1);
	map->monster.arr[1] = malloc(sizeof(int *) * map->monster.num + 1);
	map->monster.arr[2] = 0;
	map->monster.arr[0][map->monster.num] = 0;
	map->monster.arr[1][map->monster.num] = 0;
	alloc_monster(map);
}
