/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:42:01 by ksng              #+#    #+#             */
/*   Updated: 2025/08/03 23:18:54 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	image(t_map *map)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	map->img.floor = mlx_xpm_file_to_image(map->mlx_ptr,
			"Resources/floor.xpm", &width, &height);
	map->img.wall = mlx_xpm_file_to_image(map->mlx_ptr,
			"Resources/wall2.xpm", &width, &height);
	map->img.enemy = mlx_xpm_file_to_image(map->mlx_ptr,
			"Resources/enemy1.xpm", &width, &height);
	map->img.enemy1 = mlx_xpm_file_to_image(map->mlx_ptr,
			"Resources/enemy2.xpm", &width, &height);
	map->img.enemy2 = mlx_xpm_file_to_image(map->mlx_ptr,
			"Resources/enemy3.xpm", &width, &height);
	map->img.exit = mlx_xpm_file_to_image(map->mlx_ptr,
			"Resources/exit.xpm", &width, &height);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx_ptr,
			"Resources/collectible.xpm", &width, &height);
	map->img.player = mlx_xpm_file_to_image(map->mlx_ptr,
			"Resources/player1.xpm", &width, &height);
}
