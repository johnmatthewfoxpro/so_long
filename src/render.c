/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:39:42 by jfox              #+#    #+#             */
/*   Updated: 2026/03/06 16:34:20 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

// very quick function to load an image to our mlx struct.
// if the image fails to load or the path is not good, we return an error.
// that leads to the whole project being destroyed.
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

// an ugly function to load every image we need into our mlx struct.
// we use a helper function, load_img, to check if the load is a success.
void	load_map(t_game *so_long)
{
	so_long->mlx.exit[0] = load_img(so_long, "assets/exitoff.png");
	so_long->mlx.exit[1] = load_img(so_long, "assets/exiton.png");
	so_long->mlx.land[0] = load_img(so_long, "assets/land1.png");
	so_long->mlx.land[1] = load_img(so_long, "assets/land2.png");
	so_long->mlx.land[2] = load_img(so_long, "assets/land3.png");
	so_long->mlx.land[3] = load_img(so_long, "assets/land4.png");
	so_long->mlx.land[4] = load_img(so_long, "assets/land5.png");
	so_long->mlx.wall[0] = load_img(so_long, "assets/wall1.png");
	so_long->mlx.wall[1] = load_img(so_long, "assets/wall2.png");
	so_long->mlx.wall[2] = load_img(so_long, "assets/wall3.png");
	so_long->mlx.wall[3] = load_img(so_long, "assets/wall4.png");
	so_long->mlx.wall[4] = load_img(so_long, "assets/wall5.png");
	so_long->mlx.pld[0] = load_img(so_long, "assets/pmu1.png");
	so_long->mlx.pld[1] = load_img(so_long, "assets/pml1.png");
	so_long->mlx.pld[2] = load_img(so_long, "assets/pmd1.png");
	so_long->mlx.pld[3] = load_img(so_long, "assets/pmr1.png");
	so_long->mlx.gem = load_img(so_long, "assets/gem.png");
}

// this function controls printing the player/start and exit.
// by using the struct we can change the image that is printed each time we call
// this function. Like printing a different player image for direction changes
// or the different door sprite for when we have all the crystals.
static void	draw_start_end(t_game *so_long, int x, int y, char element)
{
	int	i;

	i = 0;
	if (element == 'E')
	{
		if (so_long->exit.open == 1)
			i = 1;
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.exit[i], x * TILE_SIZE, y * TILE_SIZE);
	}
	if (element == 'P')
	{
		i = so_long->player.dir;
		mlx_put_image_to_window(so_long->mlx.mlx, so_long->mlx.win,
			so_long->mlx.pld[i], x * TILE_SIZE, y * TILE_SIZE);
	}
}

// draw the specific time pointed to by draw map.
// first we ensure every tile has land down, for our transparent elements.
// then we print walls and crystals where they are found on the map.
static void	draw_tile(t_game *so_long, int x, int y)
{
	int	i;

	i = (x + y) % 5;
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
}

// a short loop that goes through our map table using y and x positions.
// it passes each postition to draw tile which then builds the map.
// at the end we draw the player and exit positions that are held in the struct.
// this implimentation allows us to call draw map anytime for a map refresh
// that respects all the same positions and allows the player to move.
void	draw_map(t_game *so_long)
{
	int	y;
	int	x;

	y = 0;
	mlx_clear_window(so_long->mlx.mlx, so_long->mlx.win,
		(mlx_color){.rgba = 0x000000FF});
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
	draw_start_end(so_long, so_long->exit.pos.x, so_long->exit.pos.y, 'E');
	draw_start_end(so_long, so_long->player.pos.x, so_long->player.pos.y, 'P');
}
