/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:24:00 by jfox              #+#    #+#             */
/*   Updated: 2026/03/05 18:51:16 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

// error handling for poor arguments in the command line or wrong file formats.
void	main_errors(int error)
{
	if (error < 0)
		ft_printf("Error\n");
	if (error == -1)
		ft_printf("Invalid Format. Must be: <so_long> <map.ber>\n");
	if (error == -2)
		ft_printf("Invalid File. Map must be a named '.ber' file.\n");
	if (error == -3)
		ft_printf("Invalid File. '*.ber' must exist.\n");
	exit(EXIT_FAILURE);
}

// we can debate the correctness of calling a square a rectangle or not.
// however for the purposes of my project, square maps are not considerered
// rectangles and are therefore not valid.
void	map_errors(int error)
{
	if (error < 0)
		ft_printf("Error\n");
	if (error == -4)
		ft_printf("Invalid map. Collums are not equal.\n");
	if (error == -5)
		ft_printf("Invalid map. The map must be rectangular.\n");
	if (error == -6)
		ft_printf("Invalid map. Map is too big. 38 x 19 is MAX grid size.\n");
	if (error == -7)
		ft_printf("Invalid map. Map files can only use: 0, 1, C, E, P.\n");
	if (error == -8)
		ft_printf("Invalid map. Maps must be surrounded by walls. ('1')\n");
	exit(EXIT_FAILURE);
}

// errors for wrong numbers of items of the maps.
// Player starts, exits and collectibles are covered.
void	element_errors(t_game *so_long)
{
	ft_printf("Error\n");
	if (so_long->end != 1)
		ft_printf("Invalid element. Maps must have 1 exit. ('E')\n");
	if (so_long->start != 1)
		ft_printf("Invalid element. Maps must have 1 player. ('P')\n");
	if (so_long->collect < 1)
		ft_printf("Invalid map. Maps need at least 1 collectible. ('C')\n");
	exit(EXIT_FAILURE);
}

// error handle for bad paths if the flood fill does not complete.
void	flood_errors(int error)
{
	if (error < 0)
		ft_printf("Error\n");
	if (error == -12)
		ft_printf("Invalid path. There is no valid path to solve the map.\n");
	exit(EXIT_FAILURE);
}

// when loading images or rendering the window with macrolibx if there are
// errors they are handled here.
void	mlx_errors(int error)
{
	if (error < 0)
		ft_printf("Error\n");
	if (error == -13)
		ft_printf("Failed MLX. The MLX INIT has failed.\n");
	if (error == -14)
		ft_printf("Failed MLX. The MLX WINDOW failed to open.\n");
	if (error == -15)
		ft_printf("Failed MLX. The MLX IMG was not created.\n");
	exit(EXIT_FAILURE);
}
