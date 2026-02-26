/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:24:00 by jfox              #+#    #+#             */
/*   Updated: 2026/02/25 20:54:55 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

void	main_errors(int error)
{
	if (error = -1)
	{
		ft_printf("Invalid arguments. Input must follow: <so_long> <map.ber>\n");
		exit(-1);
	}
}