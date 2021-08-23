/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:41:51 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/23 11:22:02 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_struct(t_game *game)
{
	if (game->sprite != NULL)
		free(game->sprite);
	game->sprite = NULL;
	if (game->coll != NULL)
		free(game->coll);
	game->coll = NULL;
	if (game->map != NULL)
		free(game->map);
	free(game);
}

void	end_game(t_game *game)
{
	free_struct(game);
	printf("GAME END\n");
	printf("You WIN !!!\n");
	exit(0);
}

void	end_program(t_game *game)
{
	printf("END PROGRAM");
	free_struct(game);
	exit(0);
}

void	game_destroy(t_game *game)
{
	free_struct(game);
}
