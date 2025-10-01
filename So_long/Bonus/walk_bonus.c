/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:33:36 by ksng              #+#    #+#             */
/*   Updated: 2025/08/03 22:28:00 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_win_or_col(t_map *map, int x, int y, int direction)
{
	if (direction == UP)
		y -= 1;
	if (direction == DOWN)
		y += 1;
	if (direction == LEFT)
		x -= 1;
	if (direction == RIGHT)
		x += 1;
	if (map->arr[y][x] == 'E' && map->c == 0)
		return (you_won_la(map));
	if (map->arr[y][x] == 'X')
		return (you_lose(map));
	if (map->arr[y][x] == 'C')
	{
		map->c -= 1;
		map->arr[y][x] = '0';
	}
}

void	walk_up(t_map *map)
{
	int	y;
	int	x;

	x = map->player.x;
	y = map->player.y;
	if (y > 0 && map->arr[y - 1][x] != '1')
	{
		check_win_or_col(map, x, y, UP);
		if (map->arr[y - 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		if (map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.floor, x * WINSIZE, y * WINSIZE);
		map->arr[y][x] = '0';
		map->walk_count++;
		y--;
		print_walk(map);
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.floor, x * WINSIZE, y * WINSIZE);
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.player, x * WINSIZE, y * WINSIZE);
		map->arr[y][x] = 'P';
	}
}

void	walk_down(t_map *map)
{
	int	y;
	int	x;

	x = map->player.x;
	y = map->player.y;
	if (y < map->y && map->arr[y + 1][x] != '1')
	{
		check_win_or_col(map, x, y, DOWN);
		if (map->arr[y + 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		if (map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.floor, x * WINSIZE, y * WINSIZE);
		map->arr[y][x] = '0';
		map->walk_count++;
		y++;
		print_walk(map);
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.floor, x * WINSIZE, y * WINSIZE);
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.player, x * WINSIZE, y * WINSIZE);
		map->arr[y][x] = 'P';
	}
}

void	walk_left(t_map *map)
{
	int	y;
	int	x;

	x = map->player.x;
	y = map->player.y;
	if (x > 0 && map->arr[y][x - 1] != '1')
	{
		check_win_or_col(map, x, y, LEFT);
		if (map->arr[y][x - 1] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		if (map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.floor, x * WINSIZE, y * WINSIZE);
		map->arr[y][x] = '0';
		map->walk_count++;
		x--;
		print_walk(map);
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.floor, x * WINSIZE, y * WINSIZE);
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.player, x * WINSIZE, y * WINSIZE);
		map->arr[y][x] = 'P';
	}
}

void	walk_right(t_map *map)
{
	int	y;
	int	x;

	x = map->player.x;
	y = map->player.y;
	if (x < map->x && map->arr[y][x + 1] != '1')
	{
		check_win_or_col(map, x, y, RIGHT);
		if (map->arr[y][x + 1] == 'E' && (map->c != 0 || map->exit == 1))
			return ;
		if (map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.floor, x * WINSIZE, y * WINSIZE);
		map->arr[y][x] = '0';
		map->walk_count++;
		x++;
		print_walk(map);
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.floor, x * WINSIZE, y * WINSIZE);
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.player, x * WINSIZE, y * WINSIZE);
		map->arr[y][x] = 'P';
	}
}
