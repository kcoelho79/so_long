/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:41:51 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/20 18:22:27 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sprite_destroy(t_game *game)
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
}

static void	struct_destroy(t_game *game)
{
	int				i;

	if (game != 0)
	{
		if (game->coll != 0)
			free(game->coll);
		if (game->map != 0)
		{
			i = 0;
			while (i < game->height)
				free(game->map[i++]);
			free(game->map);
		}
	}
}

static void	img_destroy(t_game *game)
{
	if (game->mlx_img != 0)
		mlx_destroy_image(game->mlx, game->mlx_img);
	if (game->mlx_win != 0)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx != 0)
		mlx_destroy_display(game->mlx);
}

void	game_destroy(t_game *game)
{
	sprite_destroy(game);
	img_destroy(game);
	struct_destroy(game);
	free(game);
	// printf("error: %s\n%s", msgerror, strerror(numerror));
	// exit(1);
}
