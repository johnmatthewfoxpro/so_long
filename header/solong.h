/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:17:30 by j.fox             #+#    #+#             */
/*   Updated: 2026/02/26 18:33:18 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "libft.h"
# include <math.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct	s_stack
{
	char	**map;
	int		walls;
	int		land;
	int		player;
	int		collect;
	int		door;
}			t_game;

/*********main**********/

/********errors*********/
void	main_errors(int error);

/*********map***********/
void	read_map(char *map, t_game *so_long);
char	**build_map(char *map);

/*********game**********/

/********render*********/

/*********free**********/
void	free_vals(t_game so_long);

#endif