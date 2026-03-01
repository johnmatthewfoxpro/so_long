/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:17:30 by j.fox             #+#    #+#             */
/*   Updated: 2026/03/01 18:24:44 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "libft.h"
# include <math.h>
# include <sys/time.h>
# include <stdio.h>

/*********sizes**********/
# define TILE_SIZE 50
# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_player
{
	t_pos		pos;
}				t_player;

typedef struct	s_game
{
	t_player	player;
	char		**map;
	char		**flood_map;
	int			walls;
	int			land;
	int			collect;
	int			start;
	int			exit;
	int			rows;
	int			collums;
}				t_game;

/*********main**********/

/*********map***********/
void	read_map(char *map, t_game *so_long);

/*******map-utils*******/
int		map_format(char *map);
char	**build_map(char *map);
void	check_grid(t_game *so_long);
void	check_characters(t_game *so_long);
void	check_walls(t_game *so_long);

/*******map-fill*********/
void	flood_fill(t_game *so_long);

/*********game**********/

/********render*********/

/*********free**********/
void	free_vals(t_game *so_long);
void	free_flood_map(t_game *so_long);

/********errors*********/
void	main_errors(int error);
void	map_errors(int error);
void	element_errors(t_game *so_long);

#endif