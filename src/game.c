/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:39:32 by jfox              #+#    #+#             */
/*   Updated: 2026/03/04 16:19:48 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

void	game(t_game *so_long)
{
	mlx_context				mlx;
	mlx_window_create_info	info;
	mlx_window				win;

	mlx = mlx_init();
	ft_bzero(&info, sizeof(info));
	info.title = "so_long";
	info.width = 1920;
	info.height = 1080;
	win = mlx_new_window(mlx, &info);
	//mlx_loop(mlx);
	(void)so_long;
	mlx_destroy_window(mlx, win);
	mlx_destroy_context(mlx);
	return ;
}
