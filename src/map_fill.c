/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:52:52 by jfox              #+#    #+#             */
/*   Updated: 2026/03/01 18:33:41 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

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

void	flood_fill(t_game *so_long)
{
	char	filled;
	int		y;
	int		x;

	filled = 'F';
	y = so_long->player.pos.y;
	x = so_long->player.pos.x;
	fill(so_long->flood_map, y, x, filled);
	// check_flooded
	free_flood_map(so_long);
}

