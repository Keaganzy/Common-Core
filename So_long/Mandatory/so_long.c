/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:41:28 by ksng              #+#    #+#             */
/*   Updated: 2025/08/03 22:00:07 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_cont(t_map *map)
{
	map->counter = 0;
	map->sizeerror = 0;
}

void	init_map(t_map *map, char **av)
{
	map->y = 0;
	map->x = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->mapname = av[1];
	map->walk_count = 0;
	map->player.y = 0;
	map->player.x = 0;
	map->exit = 0;
	map->arr = 0;
	map->dup_arr = 0;
	map->dup_arr2 = 0;
	map->img.player = 0;
	map->img.wall = 0;
	map->img.floor = 0;
	map->img.collectible = 0;
	map->img.exit = 0;
	map->img.enemy = 0;
	map->win_ptr = 0;
	map->mlx_ptr = 0;
	map->e_chk = 0;
	map->c_chk = 0;
	map->str_len = 0;
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		init_map(&map, av);
		init_map_cont(&map);
		map_check(&map);
		if (map.x > 30 || map.y > 16)
			error_too_big(&map);
		map.mlx_ptr = mlx_init();
		if (!map.mlx_ptr)
			return (1);
		map.win_ptr = mlx_new_window(map.mlx_ptr,
				WINSIZE * map.x, WINSIZE * map.y, "so_long");
		if (!map.win_ptr)
			return (free(map.mlx_ptr), 1);
		image(&map);
		map_print(&map);
		mlx_hook(map.win_ptr, 17, 0, closewindow, &map);
		mlx_key_hook(map.win_ptr, handle_key, &map);
		mlx_loop(map.mlx_ptr);
	}
	write(2, "\033[1;31m🛑ERROR:", 18);
	write(2, "Usage: ./so_long mapfile\n\033[0m", 30);
	exit(1);
}
// setvbuf(stdout, NULL, _IONBF, 0); //remove
