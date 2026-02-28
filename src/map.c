/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:26:56 by jfox              #+#    #+#             */
/*   Updated: 2026/02/28 19:57:15 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"


// check known collum number against every row. Throw error if not equal.
// check if map is square.
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
		y++;
	}
}

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
				map_errors(-6);
			}
			x++;
		}
		y++;
	}
}

// check valid map format '.ber'
// turn map arument into a single string.
// FInd number of collums with strlen then use i to find number of rows.
// Check collums are equal. Then check all characters on map are valid.
void	read_map(char *map, t_game *so_long)
{
	int	i;

	i = 0;
	if (!map || !map_format(map))
		main_errors(-2);
	so_long->map = build_map(map);
	// ft_printf("%s\n",so_long->map[0]);
	// ft_printf("%s\n",so_long->map[1]);
	// ft_printf("%s\n",so_long->map[2]);
	// ft_printf("%s\n",so_long->map[3]);
	// ft_printf("%s\n",so_long->map[4]);
	// ft_printf("%s\n",so_long->map[5]);
	so_long->collums = ft_strlen(so_long->map[i]);
	while (so_long->map[i])
		i++;
	so_long->rows = i;
	check_grid(so_long);
	check_characters(so_long);
	return ;
}