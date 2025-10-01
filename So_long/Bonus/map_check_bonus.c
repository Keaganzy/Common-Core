/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:57:56 by ksng              #+#    #+#             */
/*   Updated: 2025/08/05 23:22:03 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	param_check(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->y)
	{
		map->tx = 0;
		while (map->tx < map->x)
		{
			if (map->arr[y][map->tx] == 'C')
				map->c += 1;
			else if (map->arr[y][map->tx] == 'E')
				map->e += 1;
			else if (map->arr[y][map->tx] == 'P')
				map->p += 1;
			else if (map->arr[y][map->tx] == '0' ||
				map->arr[y][map->tx] == '1' || map->arr[y][map->tx] == 'X')
				;
			else
				error_elements(map);
			map->tx++;
		}
		y++;
	}
	if (map->c < 1 || map->e != 1 || map->p != 1)
		error_elements(map);
}

void	wall_check(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = ft_strlen(map->arr[y]);
	if (map->y < 2)
		error_wall(map);
	while (y < map->y)
	{
		if (map->arr[y][0] != '1' || map->arr[y][x - 1] != '1'
			|| map->arr[y][x] != '\0')
		{
			error_wall(map);
		}
		y++;
	}
	while (--x >= 0)
	{
		if (map->arr[y - 1][x] != '1')
		{
			error_wall(map);
		}
		if (map->arr[0][x] != '1')
			error_wall(map);
	}
}

void	rect_check(t_map *map)
{
	size_t	len;
	int		fd;
	char	*str;

	fd = open(map->mapname, O_RDONLY);
	if (fd == -1)
		error_open();
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		len = ft_strlen(str);
		if (str[len - 1] == '\n')
			len--;
		free(str);
		if (len != map->str_len)
			map->counter++;
		if (len == 0)
			map->sizeerror += 1;
	}
	if (map->sizeerror || map->counter > 0)
		error_size(map, map->sizeerror);
	close(fd);
	map->x = len;
}

void	file_check(t_map *map)
{
	size_t	len;

	len = ft_strlen(map->mapname);
	if (map->mapname[len - 1] != 'r')
		error_mapname();
	if (map->mapname[len - 2] != 'e')
		error_mapname();
	if (map->mapname[len - 3] != 'b')
		error_mapname();
	if (map->mapname[len - 4] != '.')
		error_mapname();
	if (!ft_strnstr(map->mapname, ".ber", len))
		error_mapname();
}

void	map_check(t_map *map)
{
	file_check(map);
	populate_arr(map);
	if (map->y == 0)
		write(2, "\033[1;31m🛑ERROR: Empty map\033[0m\n", 32);
	rect_check(map);
	wall_check(map);
	param_check(map);
	path_check(map);
	free_arr(map->dup_arr, map->y);
	free_arr(map->dup_arr2, map->y);
}
