/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:43:19 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/24 18:34:28 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	isborder(t_game *game, int i)
{
	// verifica se tem borda na 1 linha
	if (i < game->width 
	// verifica se tem borda na ultima linha
		|| i > (game->width + 1) * (game->height - 1) // 
		// verifica se e fim de linha
		|| i % (game->width + 1) == 0
		// verifica se ultimo caracter e borda
		|| i % (game->width + 1) == game->width - 1)
		return (1);
	return (0);
}

static void	isvalid(t_game *game, int i)
{
	if (game->fber[i] == 'P')
		game->count_player++;
	else if (game->fber[i] == 'E')
		game->count_exit++;
	else if (game->fber[i] == 'C')
		game->count_coll++;
	else if (game->fber[i] == '1' || game->fber[i] == '0')
		return ;
	else
		error(game, "map content is invalid\n", 0);
}

static void	isrectangular(t_game *game)
{
	int		res;
	int		len;

	// total de elementos tiles, desctando o total de /n = ao height
	len = ft_strlen(game->fber) - game->height;
	res = (game->width * game->height);
	// verificar a soma de elementos tem o mesmo tamanho da x*y
	if (res != len)
		error(game, "map matrix format is invalid \n", 1);
	if (game->height >= game->width)
		error(game, "map isn't rectangular \n", 1);
}

void	map_validate(t_game *game)
{
	int				i;

	i = -1;
	isrectangular(game);
	while (game->fber[++i] != 0)
	{
		if (game->fber[i] == '\n')
			continue ;
		if (isborder(game, i))
		{
			if (game->fber[i] != '1')
				error(game, "map isn't surrounded by walls\n", 1);
		}
		else
			isvalid(game, i);
	}
	if (game->count_player != 1 || game->count_exit != 1
		|| game->count_coll < 1)
		error(game, "map configuration is invalid\n", 1);
}
