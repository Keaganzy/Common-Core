/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:28:05 by ksng              #+#    #+#             */
/*   Updated: 2025/08/03 22:43:34 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_tile(t_map *map, int tilex, int tiley)
{
	int	state;

	state = map->arr[tiley / 64][tilex / 64];
	if (state == '0' || state == 'P' || state == 'C' || state == 'E')
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.floor, tilex, tiley);
	if (state == 'P')
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.player, tilex, tiley);
	else if (state == 'E')
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.exit, tilex, tiley);
	else if (state == 'C')
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.collectible, tilex, tiley);
	else if (state == '1')
		mlx_put_image_to_window(map->mlx_ptr,
			map->win_ptr, map->img.wall, tilex, tiley);
}

void	map_print(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			print_tile(map, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	print_walk(t_map *map)
{
	char	*move;

	move = ft_itoa(map->walk_count);
	write(1, "\r", 1);
	write(1, "\x1b[33;01m", 9);
	write(1, move, ft_strlen(move));
	write(1, "\x1b[0m", 5);
	write(1, " movements", 11);
	free(move);
}
