/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:17:30 by j.fox             #+#    #+#             */
/*   Updated: 2026/02/25 20:48:03 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "libft.h"
# include <math.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_stack
{
	int	walls;
	int	land;
	int	player;
	int	collect;
	int	door;
}	t_game;

/*********main**********/

/********errors*********/
void	main_errors(int error);

/*********map***********/
void	read_map(char **map, t_game *so_long);

/*********game**********/

/********render*********/

#endif