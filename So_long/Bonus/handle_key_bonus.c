/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:54:32 by ksng              #+#    #+#             */
/*   Updated: 2025/08/05 23:23:55 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_counter(t_map *map)
{
	int		x;
	char	*num;
	int		text_x;
	int		text_y;

	x = 0;
	while (x < map->x)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.wall,
			x * WINSIZE, 0);
		x++;
	}
	num = ft_itoa(map->walk_count);
	text_x = (map->x * WINSIZE) / 2 - 50;
	text_y = map->y * WINSIZE + 30;
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 20, 0xFFFFFF, "MOVES:");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 80, 20, 0xFFFF00, num);
	free(num);
}

int	handle_key(int key, t_map *map)
{
	find_player(map);
	if (key == ESC)
		return (closewindow(map));
	else if (key == UP && map->exit == 0)
		walk_up(map);
	else if (key == DOWN && map->exit == 0)
		walk_down(map);
	else if (key == LEFT && map->exit == 0)
		walk_left(map);
	else if (key == RIGHT && map->exit == 0)
		walk_right(map);
	if (map->exit == 0)
		print_counter(map);
	return (0);
}
