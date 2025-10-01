/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:31:06 by ksng              #+#    #+#             */
/*   Updated: 2025/08/03 22:10:19 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closewindow(t_map *map)
{
	cleanup_mlx(map);
	free_arr(map->arr, map->y);
	exit(0);
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
	write(1, "🏆🏆YOU WON!!🏆🏆\n", 27);
	write(1, "\x1b[0m", 5);
}

void	error_too_big(t_map *map)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "Map too big\n\033[0m", 17);
	free_arr(map->arr, map->y);
	exit(1);
}
