/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:42:34 by ksng              #+#    #+#             */
/*   Updated: 2025/08/03 22:08:03 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_arr(char **rev, int i)
{
	while (i > 0)
	{
		i--;
		free(rev[i]);
	}
	free(rev);
	return (0);
}

void	cleanup_mlx(t_map *map)
{
	if (map->img.player)
		mlx_destroy_image(map->mlx_ptr, map->img.player);
	if (map->img.wall)
		mlx_destroy_image(map->mlx_ptr, map->img.wall);
	if (map->img.floor)
		mlx_destroy_image(map->mlx_ptr, map->img.floor);
	if (map->img.collectible)
		mlx_destroy_image(map->mlx_ptr, map->img.collectible);
	if (map->img.exit)
		mlx_destroy_image(map->mlx_ptr, map->img.exit);
	if (map->img.enemy)
		mlx_destroy_image(map->mlx_ptr, map->img.enemy);
	if (map->win_ptr)
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	if (map->mlx_ptr)
	{
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
	}
}

void	ft_exit_free(t_map *map)
{
	cleanup_mlx(map);
	if (map->arr)
		free_arr(map->arr, map->y);
	if (map->dup_arr)
		free_arr(map->dup_arr, map->y);
	if (map->dup_arr2)
		free_arr(map->dup_arr2, map->y);
	if (map->whole_file)
		free(map->whole_file);
	if (map->line)
		free(map->line);
	exit(1);
}
