/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:26:56 by jfox              #+#    #+#             */
/*   Updated: 2026/03/01 18:32:42 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

// simply count the number of Exits, Players and Collectibles.
// loop through whole map.
// If condition at the bottom to control if the number of elements is invalid.
static void	check_elements(t_game *so_long)
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
				so_long->exit += 1;
			else if (so_long->map[y][x] == 'P')
				so_long->start += 1;
			else if (so_long->map[y][x] == 'C')
				so_long->collect += 1;
			x++;
		}
		y++;
	}
	if (so_long->exit != 1 || so_long->start != 1 || so_long->collect < 1)
	{
		free_vals(so_long);
		element_errors(so_long);
	}
}

// check valid map format '.ber'
// turn map arument into a single string.
// Find number of collums with strlen then use i to find number of rows.
// Check collums are equal. Then check all characters on map are valid.
void	read_map(char *map, t_game *so_long)
{
	int	i;

	i = 0;
	if (!map || !map_format(map))
		main_errors(-2);
	so_long->map = build_map(map);
	so_long->flood_map = build_map(map);
	so_long->collums = ft_strlen(so_long->map[i]);
	while (so_long->map[i])
		i++;
	so_long->rows = i;
	check_grid(so_long);
	check_characters(so_long);
	check_walls(so_long);
	check_elements(so_long);
	flood_fill(so_long);
	return ;
}
