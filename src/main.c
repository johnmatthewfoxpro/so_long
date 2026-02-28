/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:35:33 by jfox              #+#    #+#             */
/*   Updated: 2026/02/28 19:07:13 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

// check input arguments. Must have 2 in format <So_long> <map_file>
// zero game struct.
// send first argument to read_map for validation and parsing.
// launch game.
// free everything on close.
int	main(int argc, char **argv)
{
	t_game	so_long;

	if (argc != 2)
		main_errors(-1);
	ft_bzero(&so_long, sizeof(so_long));
	read_map(argv[1], &so_long);
	//game(&so_long);
	free_vals(&so_long);
	ft_printf("%d\n", so_long.rows);
	ft_printf("%d\n", so_long.collums);
	return (0);
}
