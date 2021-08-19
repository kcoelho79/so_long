/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:44:36 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/19 00:02:34 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		printf("SAI MANE");
	if (keycode == 119)
		game->player_up = 1;
	if (keycode == 115)
		game->player_down = 1;
	if (keycode == 97)
		game->player_left = 1;
	if (keycode == 100)
		game->player_right = 1;
	update(game);
	return (0);
}

// int	key_release(int keycode, t_game *game)
// {
// 	return(0);
// }

void	update(t_game *game)
{
	int		x;
	int		y;

	x = game->player.x;
	y = game->player.y;
	if (game->player_up != 0)
		move_up(game, x, y);
	// FIM DE JOGO
	// falta validar collect == 0 
	render(game);
	if (game->exit.x == game->player.x
		&& game->exit.y == game->player.y)
		printf("FIM DE JOGO");
}
