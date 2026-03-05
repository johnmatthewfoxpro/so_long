/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:39:42 by jfox              #+#    #+#             */
/*   Updated: 2026/03/05 18:53:53 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

static mlx_image	load_img(t_game *so_long, char *path)
{
	int			w;
	int			h;
	mlx_image	img;

	img = mlx_new_image_from_file(so_long->mlx.mlx, path, &w, &h);
	if (img == NULL)
	{
		free_mlx(so_long);
		mlx_errors(-15);
	}
	return (img);
}

void	load_map(t_game *so_long)
{
	so_long->mlx.land[0] = load_img(so_long, "assets/land1.png");
	so_long->mlx.land[1] = load_img(so_long, "assets/land2.png");
	so_long->mlx.land[2] = load_img(so_long, "assets/land3.png");
	so_long->mlx.wall[0] = load_img(so_long, "assets/wall1.png");
	so_long->mlx.wall[1] = load_img(so_long, "assets/wall2.png");
	so_long->mlx.wall[2] = load_img(so_long, "assets/wall3.png");
	so_long->mlx.exit[0] = load_img(so_long, "assets/exitoff.png");
	so_long->mlx.exit[1] = load_img(so_long, "assets/exiton.png");
	so_long->mlx.gem = load_img(so_long, "assets/gem.png");
	so_long->mlx.pmd[0] = load_img(so_long, "assets/pmd1.png");
	so_long->mlx.pmd[1] = load_img(so_long, "assets/pmd2.png");
	so_long->mlx.pmu[0] = load_img(so_long, "assets/pmu1.png");
	so_long->mlx.pmu[1] = load_img(so_long, "assets/pmu2.png");
	so_long->mlx.pml[0] = load_img(so_long, "assets/pml1.png");
	so_long->mlx.pml[1] = load_img(so_long, "assets/pml2.png");
	so_long->mlx.pmr[0] = load_img(so_long, "assets/pmr1.png");
	so_long->mlx.pmr[1] = load_img(so_long, "assets/pmr2.png");
}

static void	draw_tile(t_game *so_long, int x, int y)
{
	int	i;

	i = (x + y) % 3;
	mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
		so_long->mlx.land[i], x * TILE_SIZE, y * TILE_SIZE);
	if (so_long->map[y][x] == '1')
	{
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.wall[i], x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (so_long->map[y][x] == 'C')
	{
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.gem, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (so_long->map[y][x] == 'E')
	{
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.exit[0], x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (so_long->map[y][x] == 'P')
	{
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.pmd[0], x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	draw_map(t_game *so_long)
{
	int	y;
	int	x;

	y = 0;
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			draw_tile(so_long, x, y);
			x++;
		}
		y++;
	}
}
