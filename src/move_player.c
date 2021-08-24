/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:09:08 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/23 18:19:49 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
012
112
2P2


void	move_up(t_game *game, int x, int y)
{
	if (game->map[y - 1][x] == 0)
	{
		game->player.y -= 1;
		game->move_count++;
		printf("%i\n", game->move_count);
	}
}

void	move_down(t_game*game, int x, int y)
{
	if (game->map[y + 1][x] == 0)
	{
		game->player.y += 1;
		game->move_count++;
		printf("%i\n", game->move_count);
	}
}

void	move_left(t_game*game, int x, int y)
{
	if (game->map[y][x - 1] == 0)
	{
		game->player.x -= 1;
		game->move_count++;
		printf("%i\n", game->move_count);
	}
}

void	move_right(t_game*game, int x, int y)
{
	if (game->map[y][x + 1] == 0)
	{
		game->player.x += 1;
		game->move_count++;
		printf("%i\n", game->move_count);
	}
}
