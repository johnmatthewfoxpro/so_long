/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:26:56 by jfox              #+#    #+#             */
/*   Updated: 2026/03/06 16:38:35 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

// find length of the map name as a string.
// count through the map string name until we reach len.
// string compare the end of map string against .ber.
// if the string does not end with .ber or only includes .ber exit with error.
static int	map_format(char *map)
{
	int	len;
	int	i;

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
static char	**build_map(char *map)
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
}
