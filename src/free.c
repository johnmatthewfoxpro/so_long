/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:59:08 by jfox              #+#    #+#             */
/*   Updated: 2026/03/01 18:39:06 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

void	free_flood_map(t_game *so_long)
{
	int	i;

	i = 0;
	while (so_long->flood_map[i])
	{
		free(so_long->flood_map[i]);
		i++;
	}
	free(so_long->flood_map);
	so_long->flood_map = NULL;
	return ;
}

void	free_vals(t_game *so_long)
{
	int	i;

	i = 0;
	while (so_long->map[i])
	{
		free(so_long->map[i]);
		i++;
	}
	if (so_long->flood_map)
		free_flood_map(so_long);
	free(so_long->map);
	so_long->map = NULL;
	return ;
}
