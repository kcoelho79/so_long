/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 09:31:48 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/20 10:06:19 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_init_zero(t_game *game)
{
	game->sprite = (t_sprite *)malloc(sizeof(t_sprite));
	game->sprite->player = 0;
	game->sprite->exit = 0;
	game->sprite->coll = 0;
	game->sprite->wall = 0;
	game->sprite->ground = 0;
	game->player_up = 0;
	game->player_down = 0;
	game->player_left = 0;
	game->player_right = 0;
	game->player_coll = 0;
	game->map = 0;
	game->count_coll = 0;
	game->count_exit = 0;
	game->count_player = 0;
}

int	start(t_game *game)
{
	game_init_zero(game);
	map_init(game);
	windows_init(game);
	render(game);
	return (0);
}
