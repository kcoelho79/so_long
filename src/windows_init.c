/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 09:52:28 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/24 19:03:36 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	texture_load(t_game *game, t_img **img, char *path)
{
	int	width;
	int	height;

	/* mlx_xpm recebe uma imagem xpm, faz parsing da imagem
	 * e pega endereco, width, height, bpp size_line da imagem
	 * essas info, depois serão utilizada para desenhar a img na tela
	*/

	*img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	(*img)->width = width;
	(*img)->height = height;
}

void	windows_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error(game, "error can not load mlx", 0);
	game->mlx_win = mlx_new_window(game->mlx, game->width * 40, \
		game->height * 40, "So_long");
	if (!game->mlx_win)
		error(game, "error can not create windows", 0);
	game->mlx_img = mlx_new_image(game->mlx, game->width * 40, \
		game->height * 40);
	if (!game->mlx_img)
		error(game, "error can not create images", 0);
	texture_load(game, &game->sprite->player, "./img/player.xpm");
	texture_load(game, &game->sprite->exit, "./img/helicopter.xpm");
	texture_load(game, &game->sprite->coll, "./img/gas.xpm");
	texture_load(game, &game->sprite->wall, "./img/wall.xpm");
	texture_load(game, &game->sprite->ground, "./img/sand.xpm");
}
