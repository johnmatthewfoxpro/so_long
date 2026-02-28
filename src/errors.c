/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:24:00 by jfox              #+#    #+#             */
/*   Updated: 2026/02/28 19:54:32 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

void	main_errors(int error)
{
	if (error == -1)
	{
		ft_printf("Invalid Format. Must be: <so_long> <map.ber>\n");
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
		ft_printf("Invalid map. Map files can only use: 0, 1, C, E, P.\n");
		exit(-6);
	}
}
