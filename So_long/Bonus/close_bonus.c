/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:31:06 by ksng              #+#    #+#             */
/*   Updated: 2025/08/05 19:18:00 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	closewindow(t_map *map)
{
	cleanup_mlx(map);
	free_arr(map->arr, map->y);
	if (map->monster.num > 0)
	{
		if (map->monster.arr[0])
			free(map->monster.arr[0]);
		if (map->monster.arr[1])
			free(map->monster.arr[1]);
		if (map->monster.arr)
			free(map->monster.arr);
		map->monster.arr = NULL;
	}
	exit(1);
	return (0);
}

void	you_won_la(t_map *map)
{
	map->exit = 1;
	map->walk_count++;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	mlx_string_put(map->mlx_ptr, map->win_ptr,
		map->x / 2 * WINSIZE, map->y / 2 * WINSIZE, 0xFFFA9E, "YOU WON");
	write(1, "\n", 1);
	write(1, "\x1b[32;01m", 9);
	write(1, "🏆🏆YOU WON!!🏆🏆\n", 26);
	write(1, "\x1b[0m", 5);
}

void	you_lose(t_map *map)
{
	map->exit = 1;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	mlx_string_put(map->mlx_ptr, map->win_ptr,
		map->x / 2 * WINSIZE, map->y / 2 * WINSIZE, 0xF52200, "YOU LOSE");
	write(1, "\n", 1);
	write(1, "\x1b[31;01m", 9);
	write(1, "👾👾YOU LOSE👾👾\n", 25);
	write(1, "\x1b[0m", 5);
}

void	error_too_big(t_map *map)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "Map too big\n\033[0m", 17);
	free_arr(map->arr, map->y);
	exit(1);
}
