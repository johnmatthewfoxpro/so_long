/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:24:00 by jfox              #+#    #+#             */
/*   Updated: 2026/03/01 13:12:55 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

void	main_errors(int error)
{
	if (error == -1)
	{
		ft_printf("Invalid Format. Must be: <sl> <map.ber>\n");
		exit(-1);
	}
	if (error == -2)
	{
		ft_printf("Invalid File. Map must be a named '.ber' file.\n");
		exit(-2);
	}
	if (error == -3)
	{
		ft_printf("Invalid File. '*.ber' must exist.\n");
		exit(-3);
	}
}

void	map_errors(int error)
{
	if (error == -4)
	{
		ft_printf("Invalid map. Collums are not equal.\n");
		exit(-4);
	}
	if (error == -5)
	{
		ft_printf("Invalid map. Map can not be square.\n");
		exit(-5);
	}
	if (error == -6)
	{
		ft_printf("Invalid map. Map is too big. 38 x 21 is MAX grid size.\n");
		exit(-6);
	}
	if (error == -7)
	{
		ft_printf("Invalid map. Map files can only use: 0, 1, C, E, P.\n");
		exit(-7);
	}
	if (error == -8)
	{
		ft_printf("Invalid map. Maps must be surrounded by walls. ('1')\n");
		exit(-8);
	}
}

void	element_errors(t_game *so_long)
{

	if (so_long->exit != 1)
	{
		ft_printf("Invalid element. Maps must have 1 exit. ('E')\n");
		exit(-9);
	}
	if (so_long->start != 1)
	{
		ft_printf("Invalid element. Maps must have 1 player. ('P')\n");
		exit(-10);
	}
	if (so_long->collect < 1)
	{
		ft_printf("Invalid map. Maps must have at least 1 collectible. ('C')\n");
		exit(-11);
	}
}