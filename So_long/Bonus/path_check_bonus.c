/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:04:58 by ksng              #+#    #+#             */
/*   Updated: 2025/08/03 22:41:43 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_path_block1(int y, int x, t_map *map)
{
	char	state;

	state = map->dup_arr2[y][x];
	if (state == 'E')
	{
		map->e_chk -= 1;
		map->dup_arr2[y][x] = '1';
	}
	else if (state == '0' || state == 'P' || state == 'C')
		map->dup_arr2[y][x] = '1';
	else
		return ;
	check_path_block1(y + 1, x, map);
	check_path_block1(y - 1, x, map);
	check_path_block1(y, x - 1, map);
	check_path_block1(y, x + 1, map);
}

void	check_path_block(int y, int x, t_map *map)
{
	char	state;

	state = map->dup_arr[y][x];
	if (state == 'C')
	{
		map->c_chk -= 1;
		map->dup_arr[y][x] = '1';
	}
	else if (state == '0' || state == 'P')
		map->dup_arr[y][x] = '1';
	else
		return ;
	check_path_block(y + 1, x, map);
	check_path_block(y - 1, x, map);
	check_path_block(y, x - 1, map);
	check_path_block(y, x + 1, map);
}

void	find_player(t_map *map)
{
	map->player.y = 0;
	map->player.x = 0;
	while (map->player.y < map->y)
	{
		map->player.x = 0;
		while (map->player.x < map->x)
		{
			if (map->arr[map->player.y][map->player.x] == 'P')
				break ;
			map->player.x++;
		}
		if (map->arr[map->player.y][map->player.x] == 'P')
			break ;
		map->player.y++;
	}
}

void	path_check(t_map *map)
{
	int	p_y;
	int	p_x;

	map->c_chk = map->c;
	map->e_chk = map->e;
	find_player(map);
	p_y = map->player.y;
	p_x = map->player.x;
	check_path_block(p_y, p_x, map);
	check_path_block1(p_y, p_x, map);
	if (map->c_chk != 0 || map->e_chk >= map->e)
	{
		write(2, "\033[1;31m🛑ERROR: ", 19);
		write(2, "NO VALID PATH\n\033[0m", 19);
		free_arr(map->arr, map->y);
		free_arr(map->dup_arr, map->y);
		free_arr(map->dup_arr2, map->y);
		exit(1);
	}
}
