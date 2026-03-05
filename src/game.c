/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:39:32 by jfox              #+#    #+#             */
/*   Updated: 2026/03/05 12:16:44 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

void	game(t_game *so_long)
{
	int y;
	int x;
	int w;
	int h;
	// int i;
	// int j;
	mlx_context				mlx;
	mlx_window_create_info	window_info;
	mlx_window				win;

	mlx = mlx_init();
	ft_bzero(&window_info, sizeof(window_info));
	window_info.title = "so_long";
	window_info.width = WINDOW_WIDTH;
	window_info.height = WINDOW_HEIGHT;
	win = mlx_new_window(mlx, &window_info);

	// i = 0;
	// while (i < TILE_SIZE)
	// {
	// 	j = 0;
	// 	while (j < TILE_SIZE)
	// 	{
	// 		mlx_pixel_put(mlx, win, i, j, (mlx_color){.rgba = 0xFF0000FF});
	// 		j++;
	// 	}
	// 	i++;
	// }

	mlx_image	img;
	y = 0;
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] == '1')
			{
				img = mlx_new_image_from_file(mlx, "assets/wall1.png", &h, &w);
				mlx_put_image_to_window(mlx, win, img, x * TILE_SIZE, y * TILE_SIZE);
			}
			else if (so_long->map[y][x] == '0')
			{
				img = mlx_new_image_from_file(mlx, "assets/land1.png", &h, &w);
				mlx_put_image_to_window(mlx, win, img, x * TILE_SIZE, y * TILE_SIZE);
			}
			else if (so_long->map[y][x] == 'C')
			{
				img = mlx_new_image_from_file(mlx, "assets/gem.png", &h, &w);
				mlx_put_image_to_window(mlx, win, img, x * TILE_SIZE, y * TILE_SIZE);
			}
			else if (so_long->map[y][x] == 'E')
			{
				img = mlx_new_image_from_file(mlx, "assets/exitoff.png", &h, &w);
				mlx_put_image_to_window(mlx, win, img, x * TILE_SIZE, y * TILE_SIZE);
			}
			else if (so_long->map[y][x] == 'P')
			{
				img = mlx_new_image_from_file(mlx, "assets/player1.png", &h, &w);
				mlx_put_image_to_window(mlx, win, img, x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
	
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img);
	mlx_destroy_window(mlx, win);
	mlx_destroy_context(mlx);
	return ;
}
