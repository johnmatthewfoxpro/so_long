/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:26:56 by jfox              #+#    #+#             */
/*   Updated: 2026/02/26 18:38:00 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

// find length of the map name as a string. +1 for null, -5 for '.ber\0'
// count through the map string name until we reach len.
// string compare the end of map string against .ber.
// if the string does not end with .ber or only includes .ber exit with error.
static int	map_format(char *map)
{
	int	len;
	int i;

	len = ft_strlen(map) + 1 - 5;
	if (len <= 0)
		return (0);
	i = 0;
	while (i != len)
	{
		map++;
		i++;
	}
	if (ft_strncmp(map, ".ber", 4) != 0)
		return (0);
	return (1);
}

// join the map string so that it can be parsed.
char	**build_map(char *map)
{
	char	**complete_map;
	char	*clone;
	char	*tmp;
	int		fd;

	fd = open(map, O_RDONLY);
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

// check valid map format '.ber'
// turn map arument into a single string.
void	read_map(char *map, t_game *so_long)
{
	if (!map || !map_format(map))
		main_errors(-2);
	so_long->map = build_map(map);
	ft_printf("%s\n",so_long->map[0]);
	ft_printf("%s\n",so_long->map[1]);
	ft_printf("%s\n",so_long->map[2]);
	ft_printf("%s\n",so_long->map[3]);
	ft_printf("%s\n",so_long->map[4]);
	return ;
}