/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:17:00 by ksng              #+#    #+#             */
/*   Updated: 2025/08/03 22:09:02 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_open(void)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "failed open\n\033[0m", 17);
	exit(1);
}

void	error_elements(t_map *map)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "failed elements\n\033[0m", 21);
	free_arr(map->arr, map->y);
	free_arr(map->dup_arr, map->y);
	free_arr(map->dup_arr2, map->y);
	exit(1);
}

void	error_wall(t_map *map)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "failed wall\n\033[0m", 17);
	free_arr(map->arr, map->y);
	free_arr(map->dup_arr, map->y);
	free_arr(map->dup_arr2, map->y);
	exit(1);
}

void	error_size(t_map *map, int size_error)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "failed size\n\033[0m", 17);
	free_arr(map->arr, map->y - size_error);
	free_arr(map->dup_arr, map->y - size_error);
	free_arr(map->dup_arr2, map->y - size_error);
	exit(1);
}

void	error_mapname(void)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "Filename should be a BER extension file\n\033[0m", 45);
	exit(1);
}
