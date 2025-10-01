/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:41:46 by ksng              #+#    #+#             */
/*   Updated: 2025/08/03 23:15:50 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307
# define WINSIZE 64

typedef struct s_monster
{
	int	num;
	int	**arr;
	int	position;
}	t_monster;

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
	void	*player1;
	void	*player2;
	void	*player3;
	void	*player4;
	void	*collectible;
	void	*enemy;
	void	*enemy1;
	void	*enemy2;
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
	int			e_chk;
	int			action;
	int			tx;
	int			walk_count;
	int			counter;
	int			sizeerror;
	char		*mapname;
	char		*line;
	char		*whole_file;
	char		**arr;
	char		**dup_arr;
	char		**dup_arr2;
	int			exit;
	size_t		str_len;
	t_player	player;
	t_img		img;
	t_monster	monster;
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
void	you_lose(t_map *map);
void	error_too_big(t_map *map);
//monster
int		move_monster(t_map *map);
void	find_monster(t_map *map);
//walk_m
void	walk_up_m(t_map *map, int m);
void	walk_down_m(t_map *map, int m);
void	walk_left_m(t_map *map, int m);
void	walk_right_m(t_map *map, int m);

#endif
