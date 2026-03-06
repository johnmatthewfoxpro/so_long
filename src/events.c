/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:19:48 by jfox              #+#    #+#             */
/*   Updated: 2026/03/06 13:01:03 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

// if escape is pressed we stop the mlx_loop and so we continue game function
// 0 is when we trigger the close of the window by clicking the cross
void	event_hook(int key, void *param)
{
	if (key == 41)
	{
		ft_printf("\nYou quit the game early. Exited with 'ESC.'\n");
		mlx_loop_end((mlx_context)param);
	}
	if (key == 0)
	{
		ft_printf("\nYou quit the game early. Exited by closing the window.\n");
		mlx_loop_end((mlx_context)param);
	}
}

// follow key presses for wasd and the 4 arrow keys.
// print number of moves each key press.
void	move_hook(int key, void *param)
{
	t_game	*tmp;

	tmp = (t_game *)param;
	if (key == 82 || key == 80 || key == 81 || key == 79
		|| key == 26 || key == 4 || key == 22 || key == 7)
	{
		move_player(tmp, key);
	}
	if (tmp->exit.open == 1 && tmp->map[tmp->player.pos.y]
		[tmp->player.pos.x] == 'E')
	{
		ft_printf("\n=========== YOU WON ===========\n");
		mlx_loop_end((mlx_context)tmp->mlx.mlx);
	}
}
