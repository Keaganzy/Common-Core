/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:54:32 by ksng              #+#    #+#             */
/*   Updated: 2025/08/03 22:04:06 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (0);
}
