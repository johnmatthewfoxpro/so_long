/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:59:08 by jfox              #+#    #+#             */
/*   Updated: 2026/03/06 14:53:08 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

// a duplicate free function for the flood fill map copy of my main map.
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
}

// free the map string held in my game struct.
// if the flood fill map exists, free that as well.
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
}

// a continued free of my mlx images.
// at the end we ensure to free the mlx window and the mlx context before
// freeing all the values in the game structure, like the maps.
static void	free_mlx_cont(t_game *so_long)
{
	if (so_long->mlx.gem)
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.gem);
	if (so_long->mlx.pld[0])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.pld[0]);
	if (so_long->mlx.pld[1])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.pld[1]);
	if (so_long->mlx.pld[2])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.pld[2]);
	if (so_long->mlx.pld[3])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.pld[3]);
	if (so_long->mlx.win)
		mlx_destroy_window(so_long->mlx.mlx, so_long->mlx.win);
	if (so_long->mlx.mlx)
		mlx_destroy_context(so_long->mlx.mlx);
	free_vals(so_long);
}

// simply free every image in my mlx struct if it exits.
void	free_mlx(t_game *so_long)
{
	if (so_long->mlx.exit[0])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.exit[0]);
	if (so_long->mlx.exit[1])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.exit[1]);
	if (so_long->mlx.land[0])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.land[0]);
	if (so_long->mlx.land[1])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.land[1]);
	if (so_long->mlx.land[2])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.land[2]);
	if (so_long->mlx.land[3])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.land[3]);
	if (so_long->mlx.land[4])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.land[4]);
	if (so_long->mlx.wall[0])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.wall[0]);
	if (so_long->mlx.wall[1])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.wall[1]);
	if (so_long->mlx.wall[2])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.wall[2]);
	if (so_long->mlx.wall[3])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.wall[3]);
	if (so_long->mlx.wall[4])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.wall[4]);
	free_mlx_cont(so_long);
}
