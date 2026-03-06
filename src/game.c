/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:39:32 by jfox              #+#    #+#             */
/*   Updated: 2026/03/06 16:30:27 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

// a small function to initialize the mlx window and mlx.
// on errors this frees the whole game, prints an error and quits.
static void	game_init(t_game *so_long, mlx_window_create_info window_info)
{
	so_long->mlx.mlx = mlx_init();
	if (so_long->mlx.mlx == NULL)
	{
		free_mlx(so_long);
		mlx_errors(-13);
	}
	so_long->mlx.win = mlx_new_window(so_long->mlx.mlx, &window_info);
	if (so_long->mlx.win == NULL)
	{
		free_mlx(so_long);
		mlx_errors(-14);
	}
}

// here we initialize all our mlx elements.
// call window struct and define its size based on the size of the map.
// initate the mlx, check for errors inside that function.
// set fps goal to control memory usage.
// set a player direction for when we draw the map.
// load all map images, quit on load errors, once loaded build the map.
// set hooks for player imput, window and keyboard events.
// finally loop with mlx_loop until exit or player victory.
// once loop ends, free whole game, destroy mlx, with free_mlx.
void	game(t_game *so_long)
{
	mlx_window_create_info	window_info;

	ft_bzero(&window_info, sizeof(window_info));
	window_info.title = "so_long";
	window_info.width = so_long->collums * TILE_SIZE;
	window_info.height = so_long->rows * TILE_SIZE;
	game_init(so_long, window_info);
	mlx_set_fps_goal(so_long->mlx.mlx, 30);
	so_long->player.dir = 2;
	load_map(so_long);
	draw_map(so_long);
	mlx_on_event(so_long->mlx.mlx, so_long->mlx.win,
		MLX_KEYDOWN, event_hook, so_long->mlx.mlx);
	mlx_on_event(so_long->mlx.mlx, so_long->mlx.win,
		MLX_WINDOW_EVENT, event_hook, so_long->mlx.mlx);
	mlx_on_event(so_long->mlx.mlx, so_long->mlx.win,
		MLX_KEYDOWN, move_hook, so_long);
	mlx_loop(so_long->mlx.mlx);
	free_mlx(so_long);
}
