/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:17:30 by j.fox             #+#    #+#             */
/*   Updated: 2026/03/06 13:01:24 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "libft.h"
# include "../macrolibx/includes/mlx.h"
# include "../macrolibx/includes/mlx_profile.h"
# include "../macrolibx/includes/mlx_extended.h"
# include <sys/time.h>
# include <stdio.h>
# include <math.h>

/*********sizes**********/
# define TILE_SIZE 50
# define WINDOW_HEIGHT 980
# define WINDOW_WIDTH 1920

/********structs*********/
typedef struct s_mlx
{
	mlx_context	mlx;
	mlx_window	win;
	mlx_image	gem;
	mlx_image	pmd[2];
	mlx_image	pmu[2];
	mlx_image	pml[2];
	mlx_image	pmr[2];
	mlx_image	land[5];
	mlx_image	wall[5];
	mlx_image	exit[2];
}				t_mlx;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_player
{
	t_pos		pos;
	char		dir;
}				t_player;

typedef struct s_exit
{
	t_pos		pos;
	int			open;
}				t_exit;

typedef struct s_game
{
	t_mlx		mlx;
	t_player	player;
	t_exit		exit;
	char		**map;
	char		**flood_map;
	int			counter;
	int			collums;
	int			rows;
	int			collect;
	int			start;
	int			end;
}				t_game;

/*********main**********/

/*********map***********/
void	read_map(char *map, t_game *so_long);
int		map_format(char *map);
char	**build_map(char *map);

/*******map-utils*******/
void	check_grid(t_game *so_long);
void	check_elements(t_game *so_long);
void	set_start_end(t_game *so_long, int x, int y);
void	check_characters(t_game *so_long);
void	check_walls(t_game *so_long);

/*******map-fill*********/
void	flood_fill(t_game *so_long);

/*********game**********/
void	game(t_game *so_long);

/********render*********/
void	load_map(t_game *so_long);
void	draw_map(t_game *so_long);

/********events*********/
void	event_hook(int key, void *param);
void	move_hook(int key, void *param);

/*******movement********/
void	move_player(t_game *so_long, int key);

/*********free**********/
void	free_vals(t_game *so_long);
void	free_flood_map(t_game *so_long);
void	free_mlx(t_game *so_long);

/********errors*********/
void	main_errors(int error);
void	map_errors(int error);
void	element_errors(t_game *so_long);
void	flood_errors(int error);
void	mlx_errors(int error);

#endif