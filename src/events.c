/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:44:36 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/22 22:59:53 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{	
	if (keycode == 65307)
		game_destroy(game);
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

static void	iscollectable(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->count_coll)
	{
		if (game->coll[i].x == game->player.x
			&& game->coll[i].y == game->player.y)
		{
			game->coll[i].x = -1;
			game->coll[i].y = -1;
			game->player_coll++;
		}
		i++;
	}
}

int	destroy_hook(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	game_destroy(game);
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
	if (game->player.x == game->exit.x
		&& game->player.y == game->exit.y)
		if (game->count_coll == game->player_coll)
			exit(0);
					// criar exit aqui

	iscollectable(game);
	render(game);
}
