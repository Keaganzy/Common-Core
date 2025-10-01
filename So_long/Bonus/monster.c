/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:26:30 by ksng              #+#    #+#             */
/*   Updated: 2025/08/05 19:07:20 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	randomize_monster(t_map *map, int m)
{
	if (map->monster.position == 0)
	{
		walk_right_m(map, m);
		map->monster.position++;
	}
	else if (map->monster.position == 1)
	{
		walk_down_m(map, m);
		map->monster.position++;
	}
	else if (map->monster.position == 2)
	{
		walk_left_m(map, m);
		map->monster.position++;
	}
	else if (map->monster.position == 3)
	{
		walk_up_m(map, m);
		map->monster.position++;
	}
	else
		map->monster.position = 0;
}

static void	monster_animation(t_map *map, int x, int y)
{
	if (map->action % 5000 == 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.enemy,
			x * WINSIZE, y * WINSIZE);
	}
	if (map->action % 7000 == 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.enemy1,
			x * WINSIZE, y * WINSIZE);
	}
	if (map->action % 11000 == 0)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.enemy2,
			x * WINSIZE, y * WINSIZE);
	}
}

int	move_monster(t_map *map)
{
	int	m;
	int	x;
	int	y;

	m = 0;
	if (map->exit == 1)
		return (0);
	while (m < map->monster.num && map->exit != 1)
	{
		y = map->monster.arr[0][m];
		x = map->monster.arr[1][m];
		monster_animation(map, x, y);
		if (map->action % 50000 == 0)
			randomize_monster(map, m);
		m++;
	}
	map->action++;
	return (0);
}
