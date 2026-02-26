/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:26:56 by jfox              #+#    #+#             */
/*   Updated: 2026/02/26 12:19:58 by jfox             ###   ########.fr       */
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

// // join the map string so that it can be parsed.
// char	*build_map(char *map)
// {
// 	char	*clone;
// 	int		fd;

// 	fd = open(map, O_RDONLY);
// 	while (map)
// 	{

// 		clone = ft_strjoin_gnl("", clone)
// 	}
// 	return (clone);
// }

// check valid map format '.ber'
// turn map arument into a single string.
void	read_map(char *map, t_game *so_long)
{
	if (!map || !map_format(map))
		main_errors(-2);
	so_long->map = build_map(map);
	ft_printf("%s\n",so_long->map);
	return ;
}