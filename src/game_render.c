/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 09:57:26 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/20 09:58:12 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_sprite(t_game *root, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(root->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

static void	draw_env(t_game *game, int i, int j)
{
	int				k;

	if (game->exit.x == i && game->exit.y == j)
		draw_sprite(game, game->sprite->exit, i * 40, j * 40);
	k = -1;
	while (++k < game->count_coll)
		if (game->coll[k].x == i && game->coll[k].y == j)
			draw_sprite(game, game->sprite->coll, i * 40, j * 40);
	if (game->player.x == i && game->player.y == j)
		draw_sprite(game, game->sprite->player, i * 40, j * 40);
}

void	render(t_game *game)
{
	int				x;
	int				y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 1)
				draw_sprite(game, game->sprite->wall, x * 40, y * 40);
			else
				draw_sprite(game, game->sprite->ground, x * 40, y * 40);
			draw_env(game, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->mlx_img, 0, 0);
}
