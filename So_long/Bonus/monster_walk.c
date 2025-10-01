/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_walk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:37:35 by ksng              #+#    #+#             */
/*   Updated: 2025/08/03 22:42:33 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_resume_monster(t_map *map, int x, int y, int dir)
{
	if (dir == UP)
		y -= 1;
	if (dir == DOWN)
		y += 1;
	if (dir == LEFT)
		x -= 1;
	if (dir == RIGHT)
		x += 1;
	if (map->arr[y][x] == 'P')
		return (you_lose(map));
}

void	walk_down_m(t_map *map, int m)
{
	int	x;
	int	y;

	y = map->monster.arr[0][m];
	x = map->monster.arr[1][m];
	if (y < map->y && map->arr[y + 1][x] != '1')
	{
		move_resume_monster(map, x, y, DOWN);
		if (map->arr[y + 1][x] == 'E' || map->arr[y + 1][x] == 'C'
			|| map->arr[y + 1][x] == 'X' || map->exit == 1)
			return ;
		if (map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
			x * WINSIZE, y * WINSIZE);
		map->arr[y][x] = '0';
		y++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
		x * WINSIZE, y * WINSIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.enemy,
		x * WINSIZE, y * WINSIZE);
	map->arr[y][x] = 'X';
	map->monster.arr[0][m] = y;
}

void	walk_up_m(t_map *map, int m)
{
	int	x;
	int	y;

	y = map->monster.arr[0][m];
	x = map->monster.arr[1][m];
	if (y > 0 && map->arr[y - 1][x] != '1')
	{
		move_resume_monster(map, x, y, UP);
		if (map->arr[y - 1][x] == 'E' || map->arr[y - 1][x] == 'C'
			|| map->arr[y - 1][x] == 'X' || map->exit == 1)
			return ;
		if (map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
			x * WINSIZE, y * WINSIZE);
		map->arr[y][x] = '0';
		y--;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
		x * WINSIZE, y * WINSIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.enemy,
		x * WINSIZE, y * WINSIZE);
	map->arr[y][x] = 'X';
	map->monster.arr[0][m] = y;
}

void	walk_left_m(t_map *map, int m)
{
	int	x;
	int	y;

	y = map->monster.arr[0][m];
	x = map->monster.arr[1][m];
	if (x > 0 && map->arr[y][x - 1] != '1')
	{
		move_resume_monster(map, x, y, LEFT);
		if (map->arr[y][x - 1] == 'E' || map->arr[y][x - 1] == 'C'
			|| map->arr[y][x - 1] == 'X' || map->exit == 1)
			return ;
		if (map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
			x * WINSIZE, y * WINSIZE);
		map->arr[y][x] = '0';
		x--;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
		x * WINSIZE, y * WINSIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.enemy,
		x * WINSIZE, y * WINSIZE);
	map->arr[y][x] = 'X';
	map->monster.arr[1][m] = x;
}

void	walk_right_m(t_map *map, int m)
{
	int	x;
	int	y;

	y = map->monster.arr[0][m];
	x = map->monster.arr[1][m];
	if (x < map->x && map->arr[y][x + 1] != '1')
	{
		move_resume_monster(map, x, y, RIGHT);
		if (map->arr[y][x + 1] == 'E' || map->arr[y][x + 1] == 'C'
			|| map->arr[y][x + 1] == 'X' || map->exit == 1)
			return ;
		if (map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
			x * WINSIZE, y * WINSIZE);
		map->arr[y][x] = '0';
		x++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.floor,
		x * WINSIZE, y * WINSIZE);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.enemy,
		x * WINSIZE, y * WINSIZE);
	map->arr[y][x] = 'X';
	map->monster.arr[1][m] = x;
}
