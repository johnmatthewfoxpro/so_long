/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:24:00 by jfox              #+#    #+#             */
/*   Updated: 2026/02/26 11:30:30 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

void	main_errors(int error)
{
	if (error == -1)
	{
		ft_printf("Invalid arguments. Input must follow: <so_long> <map.ber>\n");
		exit(-1);
	}
	if (error == -2)
	{
		ft_printf("Invalid map format. Map must be a named '.ber' file.\n");
		exit(-2);
	}
}