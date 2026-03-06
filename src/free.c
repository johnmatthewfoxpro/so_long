/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:59:08 by jfox              #+#    #+#             */
/*   Updated: 2026/03/06 11:19:57 by jfox             ###   ########.fr       */
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
}

static void	free_mlx_cont(t_game *so_long)
{
	if (so_long->mlx.gem)
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.gem);
	if (so_long->mlx.pmd[0])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.pmd[0]);
	if (so_long->mlx.pmd[1])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.pmd[1]);
	if (so_long->mlx.pmu[0])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.pmu[0]);
	if (so_long->mlx.pmu[1])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.pmu[1]);
	if (so_long->mlx.pml[0])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.pml[0]);
	if (so_long->mlx.pml[1])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.pml[1]);
	if (so_long->mlx.pmr[0])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.pmr[0]);
	if (so_long->mlx.pmr[1])
		mlx_destroy_image(so_long->mlx.mlx, so_long->mlx.pmr[1]);
	if (so_long->mlx.win)
		mlx_destroy_window(so_long->mlx.mlx, so_long->mlx.win);
	if (so_long->mlx.mlx)
		mlx_destroy_context(so_long->mlx.mlx);
	free_vals(so_long);
}

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
