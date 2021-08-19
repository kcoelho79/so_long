/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:44:36 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/19 13:38:00 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{	
	write(1, &keycode, 1);
	if (keycode == 65307)
		printf("SAI MANE");
	else if (keycode == 'w')
		game->player_up = 1;
	else if (keycode == 's')
		game->player_down = 1;
	else if (keycode == 'a')
		game->player_left = 1;
	else if (keycode == 'd')
		game->player_right = 1;
	else
		return (0);
	update(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 'w')
		game->player_up = 0;
	else if (keycode == 's')
		game->player_down = 0;
	else if (keycode == 'a')
		game->player_left = 0;
	else if (keycode == 'd')
		game->player_right = 0;
	else
		return (0);
	update(game);
	return (0);
}

void	update(t_game *game)
{
	int		x;
	int		y;

	x = game->player.x;
	y = game->player.y;
	if (game->player_up == 1)
		move_up(game, x, y);
	else if (game->player_down == 1)
		move_down(game, x, y);
	else if (game->player_left == 1)
		move_left(game, x, y);
	else if (game->player_right == 1)
		move_right(game, x, y);
	render(game);
}
