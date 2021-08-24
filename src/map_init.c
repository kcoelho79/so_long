/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 09:39:15 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/24 18:23:36 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_map_dimension(t_game *game)
{
	size_t	i;

	i = 0;
	game->height = 0;
	game->width = 0;
	while (game->fber[i] != '\0')
	{
		if (game->fber[i] == '\n')
			game->height++;
		if (game->height == 0)
			game->width++;
		i++;
	}
}

static void	get_coord(t_game *game, int i, int *obj)
{
/* o i é a posição do caracter do arquivo map.ber
	como se trata de uma matriz igual, dividindo 
	pela posiçao, se tem a posicao da  linha (y) e o resto
	da divisão se tem a posicao da coluna (x)
 */
	if (game->fber[i] == 'P')
	{
		game->player.x = i % (game->width + 1);
		game->player.y = i / (game->width + 1);
		game->fber[i] = '0';
	}
	else if (game->fber[i] == 'E')
	{
		game->exit.x = i % (game->width + 1);
		game->exit.y = i / (game->width + 1);
		game->fber[i] = '0';
	}
	else if (game->fber[i] == 'C')
	{
	/* no game pode ter mais de um item coll,
	 *obj e o indice em relacao a memoria, 
	 matematica de ponteiros 
	 */
		game->coll[*obj].x = i % (game->width + 1);
		game->coll[*obj].y = i / (game->width + 1);
		game->fber[i] = '0';
		(*obj)++;
	}
}

static void	create_matrix_map(t_game *game)
{
	size_t	i;
	int		row;
	int		col;
	int		obj;

	obj = 0;
	i = 0;
	row = -1;
	/* Alocacao memoria, da matriz **map tamanho do total de linha */
	game->map = (int **)malloc(sizeof(int *) * game->height);
	game->coll = (t_coord *)malloc(sizeof(t_coord) * game->count_coll);
	if (!game->map || !game->coll)
		error(game, "map_init error malloc", errno);
	while (++row < game->height)
	{
		game->map[row] = (int *)malloc(sizeof(int) * game->width);
		col = 0;
		while (col < game->width)
		{
			get_coord(game, i, &obj);
			game->map[row][col++] = game->fber[i++] - 48;
		}
		i++;
	}
	free(game->fber);
}	

void	map_init(t_game	*game)
{
	 get_map_dimension(game);
	 map_validate(game);
	 create_matrix_map(game);
}
