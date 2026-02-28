/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:14:00 by jfox              #+#    #+#             */
/*   Updated: 2026/02/28 17:48:09 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

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
	return (complete_map);
}

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