/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:59:08 by jfox              #+#    #+#             */
/*   Updated: 2026/02/26 18:38:37 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

void	free_vals(t_game so_long)
{
	int	i;

	i = 0;
	while (so_long.map[i])
	{
		free(so_long.map[i]);
		i++;
	}
	free(so_long.map);
	return ;
}