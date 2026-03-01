/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:14:00 by jfox              #+#    #+#             */
/*   Updated: 2026/03/01 18:32:55 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

// find length of the map name as a string.
// count through the map string name until we reach len.
// string compare the end of map string against .ber.
// if the string does not end with .ber or only includes .ber exit with error.
int	map_format(char *map)
{
	int	len;
	int i;

	len = ft_strlen(map);
	if (len <= 4)
		return (0);
	i = 0;
	while (i != len)
	{
		map++;
		i++;
	}
	if (ft_strncmp(map - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

// join the map string so that it can be parsed.
// if there is nothing to read with open, send error.
// the complete map in the result of this table works to define collums, rows.
// **map[0][0] this is the top left position of the map. First[0] is the row.
// The second [0] is the collum.
char	**build_map(char *map)
{
	char	**complete_map;
	char	*clone;
	char	*tmp;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		main_errors(-3);
	tmp = get_next_line(fd);
	complete_map = NULL;
	clone = NULL;
	while (tmp)
	{
		clone = ft_strjoin_gnl(clone, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	complete_map = ft_split(clone, '\n');
	free(clone);
	close(fd);
	return (complete_map);
}

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
			else if (so_long->map[y][x] == 'P')
			{
				so_long->player.pos.x = x;
				so_long->player.pos.y = y;
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
		if (so_long->map[0][i] != '1' || so_long->map[so_long->rows - 1][i] != '1')
			valid = 0;
		i++;
	}
	i = 1;
	while (so_long->map[i])
	{
		if (so_long->map[i][0] != '1' || so_long->map[i][so_long->collums - 1] != '1')
			valid = 0;
		i++;
	}
	if (valid == 0)
	{
		free_vals(so_long);
		map_errors(-8);
	}
}
