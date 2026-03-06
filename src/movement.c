/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:28:07 by jfox              #+#    #+#             */
/*   Updated: 2026/03/06 13:03:38 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/solong.h"

// check if we are on the collectible gems, if so reduce the number of gems
// in the struct so_long by 1. And print a 0 to the map.
// This ensures when we draw map next time the crytal will dissapear.
// if crystals = 0, we say the door is open.
static void collect_gem(t_game *so_long)
{
	so_long->collect--;
	so_long->map[so_long->player.pos.y][so_long->player.pos.x] = '0';
	if (so_long->collect == 0)
		so_long->exit.open = 1;
}

// check if the tile we want to move onto is a wall. If it is, return a 0.
// this function returning a zero stops the player position changing in the
// previous function.
static int	can_move(t_game *so_long, char dir)
{
	if (dir == 'u' && so_long->map[so_long->player.pos.y - 1]
		[so_long->player.pos.x] == '1')
		return (0);
	if (dir == 'l' && so_long->map[so_long->player.pos.y]
		[so_long->player.pos.x - 1] == '1')
		return (0);
	if (dir == 'd' && so_long->map[so_long->player.pos.y + 1]
		[so_long->player.pos.x] == '1')
		return (0);
	if (dir == 'r' && so_long->map[so_long->player.pos.y]
		[so_long->player.pos.x + 1] == '1')
		return (0);
	so_long->counter++;
	ft_printf("\rMoves: %d", so_long->counter);
	return (1);
}

// check the 'direction' of the player according to arrow press.
// use that with a bool can move to determine if the player can move.
// if the player is now on a gem, call collect gem function.
void	move_player(t_game *so_long, int key)
{
	if ((key == 82 || key == 26) && (can_move(so_long, 'u') == 1))
	{
		so_long->player.dir = 'u';
		so_long->player.pos.y -= 1;
	}
	if ((key == 80 || key == 4) && (can_move(so_long, 'l') == 1))
	{
		so_long->player.dir = 'l';
		so_long->player.pos.x -= 1;
	}
	if ((key == 81 || key == 22) && (can_move(so_long, 'd') == 1))
	{
		so_long->player.dir = 'd';
		so_long->player.pos.y += 1;
	}
	if ((key == 79 || key == 7) && (can_move(so_long, 'r') == 1))
	{
		so_long->player.dir = 'r';
		so_long->player.pos.x += 1;
	}
	if (so_long->map[so_long->player.pos.y][so_long->player.pos.x] == 'C')
		collect_gem(so_long);
	draw_map(so_long);
}
