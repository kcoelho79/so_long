/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:41:51 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/23 14:50:04 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	root_destroy(t_game *game)
{
	if (game != 0)
	{
		if (game->sprite->ground != 0)
			mlx_destroy_image(game->mlx, game->sprite->ground);
		if (game->sprite->wall != 0)
			mlx_destroy_image(game->mlx, game->sprite->wall);
		if (game->sprite->coll != 0)
			mlx_destroy_image(game->mlx, game->sprite->coll);
		if (game->sprite->exit != 0)
			mlx_destroy_image(game->mlx, game->sprite->exit);
		if (game->sprite->player != 0)
			mlx_destroy_image(game->mlx, game->sprite->player);
		if (game->mlx_img != 0)
			mlx_destroy_image(game->mlx, game->mlx_img);
		if (game->mlx_win != 0)
			mlx_destroy_window(game->mlx, game->mlx_win);
		if (game->mlx != 0)
			mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

static void	free_struct(t_game *game)
{
	int	i;

	if (game->sprite != NULL)
		free(game->sprite);
	game->sprite = NULL;
	if (game->coll != NULL)
		free(game->coll);
	game->coll = NULL;
	if (game->map != 0)
	{
		i = 0;
		while (i < game->height)
			free(game->map[i++]);
		free(game->map);
	}
	free(game);
}

void	end_game(t_game *game)
{
	root_destroy(game);
	free_struct(game);
	printf("GAME END\n");
	printf("You WIN !!!\n");
	exit(0);
}

void	end_program(t_game *game)
{
	printf("END PROGRAM");
	root_destroy(game);
	free_struct(game);
	exit(0);
}

void	game_destroy(t_game *game)
{
	free_struct(game);
}
