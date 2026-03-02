/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:52:52 by jfox              #+#    #+#             */
/*   Updated: 2026/03/02 10:00:00 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

// recursive search using a basic flood fill code.
// return if we hit a wall or an already filled position.
// If not, fill the position we are on and then call the function again.
// checking 1 space in every direction from our original position.
static void	fill(char **flood_map, int y, int x, char filled)
{
	if (flood_map[y][x] == '1' || flood_map[y][x] == filled)
		return ;
	else
		flood_map[y][x] = filled;
	fill(flood_map, y - 1, x, filled);
	fill(flood_map, y + 1, x, filled);
	fill(flood_map, y, x - 1, filled);
	fill(flood_map, y, x + 1, filled);
}

// super simple function to check that the flooded map is only map up of walls
// and flooded cells.
// if any cell is not a 1 or an F, we return an error.
static void	check_flooded(t_game *so_long)
{
	int	y;
	int	x;

	y = 0;
	while (so_long->flood_map[y])
	{
		x = 0;
		while (so_long->flood_map[y][x])
		{
			if (so_long->flood_map[y][x] != '1'
				&& so_long->flood_map[y][x] != 'F')
			{
				free_vals(so_long);
				flood_errors(-12);
			}
			x++;
		}
		y++;
	}
}

// define a character to fill in the paths of the map.
// set x and y coodinates for the start position on the map.
// pass to a flood fill function.
// check the map has been filled, exit out on fail.
// free the flooded map.
void	flood_fill(t_game *so_long)
{
	char	filled;
	int		y;
	int		x;

	filled = 'F';
	y = so_long->player.pos.y;
	x = so_long->player.pos.x;
	fill(so_long->flood_map, y, x, filled);
	check_flooded(so_long);
	free_flood_map(so_long);
}
