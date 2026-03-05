/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:14:00 by jfox              #+#    #+#             */
/*   Updated: 2026/03/05 13:52:38 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

// check known collum number against every row. Throw error if not equal.
// check if map is square.
// check map is not bigger than display size. 1920 x 1080.
void	check_grid(t_game *so_long)
{
	int	y;

	y = 0;
	while (so_long->map[y])
	{
		if ((int)ft_strlen(so_long->map[y]) != so_long->collums)
		{
			free_vals(so_long);
			map_errors(-4);
		}
		if ((int)ft_strlen(so_long->map[y]) == so_long->rows)
		{
			free_vals(so_long);
			map_errors(-5);
		}
		if (so_long->rows * TILE_SIZE > WINDOW_HEIGHT
			|| so_long->collums * TILE_SIZE > WINDOW_WIDTH)
		{
			free_vals(so_long);
			map_errors(-6);
		}
		y++;
	}
}

// simply count the number of Exits, Players and Collectibles.
// loop through whole map.
// If condition at the bottom to control if the number of elements is invalid.
void	check_elements(t_game *so_long)
{
	int	y;
	int	x;

	y = 0;
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] == 'E')
				so_long->end += 1;
			else if (so_long->map[y][x] == 'P')
				so_long->start += 1;
			else if (so_long->map[y][x] == 'C')
				so_long->collect += 1;
			x++;
		}
		y++;
	}
	if (so_long->end != 1 || so_long->start != 1 || so_long->collect < 1)
	{
		free_vals(so_long);
		element_errors(so_long);
	}
}

// super easy compartmentalisation function to save the locations of the player
// and exit. This allows them to be used later for animations and events.
void	set_start_end(t_game *so_long, int x, int y)
{
	if (so_long->map[y][x] == 'P')
	{
		so_long->player.pos.x = x;
		so_long->player.pos.y = y;
	}
	if (so_long->map[y][x] == 'E')
	{
		so_long->exit.pos.x = x;
		so_long->exit.pos.y = y;
	}
}

// check the map only uses correct characters. Error is anything is incorrect.
// This also allows us to check is rows have spaces.
// Finally we use pos struct to pass the starting coordinates of the P char.
void	check_characters(t_game *so_long)
{
	int	y;
	int	x;

	y = 0;
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] != '0' && so_long->map[y][x] != '1'
				&& so_long->map[y][x] != 'C' && so_long->map[y][x] != 'E'
				&& so_long->map[y][x] != 'P')
			{
				free_vals(so_long);
				map_errors(-7);
			}
			else if (so_long->map[y][x] == 'P' || so_long->map[y][x] == 'E')
			{
				set_start_end(so_long, x, y);
			}
			x++;
		}
		y++;
	}
}

// check all edges of map for 1's. If not all 1's, map is invalid.
void	check_walls(t_game *so_long)
{
	int	i;
	int	valid;

	i = 0;
	valid = 1;
	while (so_long->map[0][i])
	{
		if (so_long->map[0][i] != '1'
			|| so_long->map[so_long->rows - 1][i] != '1')
			valid = 0;
		i++;
	}
	i = 1;
	while (so_long->map[i])
	{
		if (so_long->map[i][0] != '1'
			|| so_long->map[i][so_long->collums - 1] != '1')
			valid = 0;
		i++;
	}
	if (valid == 0)
	{
		free_vals(so_long);
		map_errors(-8);
	}
}
