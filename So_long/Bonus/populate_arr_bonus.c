/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_arr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:03:18 by ksng              #+#    #+#             */
/*   Updated: 2025/08/03 22:40:40 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	populate_arr_cont(t_map *map)
{
	if (!map->whole_file)
		ft_exit_free(map);
	map->arr = ft_split(map->whole_file, '\n');
	map->dup_arr = ft_split(map->whole_file, '\n');
	map->dup_arr2 = ft_split(map->whole_file, '\n');
	if (!map->arr || !map->dup_arr || !map->dup_arr2)
		ft_exit_free(map);
	free(map->whole_file);
}

static void	get_str_len(t_map *map)
{
	if (map->y == 0)
	{
		map->str_len = ft_strlen(map->line);
		if (map->line[map->str_len - 1] == '\n')
			map->str_len--;
	}
}

void	populate_arr(t_map *map)
{
	int		fd;
	char	*temp;

	map->whole_file = NULL;
	fd = open(map->mapname, O_RDONLY);
	if (fd == -1)
		error_open();
	while (1)
	{
		map->line = get_next_line(fd);
		if (map->line == NULL)
			break ;
		get_str_len(map);
		temp = ft_strjoin1(map->whole_file, map->line);
		free(map->whole_file);
		map->whole_file = temp;
		free(map->line);
		if (!map->whole_file)
			ft_exit_free(map);
		map->y++;
	}
	close(fd);
	populate_arr_cont(map);
}
