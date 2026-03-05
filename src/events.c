/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:19:48 by jfox              #+#    #+#             */
/*   Updated: 2026/03/05 18:40:00 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

// if escape is pressed we stop the mlx_loop and so we continue game function
// 0 is when we trigger the close of the window by clicking the cross
void	event_hook(int key, void *param)
{
	if (key == 41)
		mlx_loop_end((mlx_context)param);
	if (key == 0)
		mlx_loop_end((mlx_context)param);
}
