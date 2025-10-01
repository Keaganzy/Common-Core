/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:41:46 by ksng              #+#    #+#             */
/*   Updated: 2025/08/05 22:53:06 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307
# define WINSIZE 64

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*enemy;
	void	*exit;
}	t_img;

typedef struct s_map
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			y;
	int			x;
	int			e;
	int			c;
	int			p;
	int			c_chk;
	size_t		str_len;
	int			e_chk;
	int			walk_count;
	char		*mapname;
	char		*line;
	char		*whole_file;
	char		**arr;
	char		**dup_arr;
	char		**dup_arr2;
	int			counter;
	int			sizeerror;
	int			exit;
	t_player	player;
	t_img		img;
}	t_map;

int		handle_key(int key, t_map *map);
void	find_player(t_map *map);
void	map_check(t_map *map);
void	image(t_map *map);
void	map_print(t_map *map);
void	print_walk(t_map *map);
void	populate_arr(t_map *map);
void	path_check(t_map *map);
//free
void	ft_exit_free(t_map *map);
int		free_arr(char **rev, int i);
void	cleanup_mlx(t_map *map);
//errors
void	error_open(void);
void	error_elements(t_map *map);
void	error_wall(t_map *map);
void	error_size(t_map *map, int size_error);
void	error_mapname(void);
//walk
void	walk_up(t_map *map);
void	walk_down(t_map *map);
void	walk_left(t_map *map);
void	walk_right(t_map *map);
//close
int		closewindow(t_map *map);
void	you_won_la(t_map *map);
void	error_too_big(t_map *map);

#endif
