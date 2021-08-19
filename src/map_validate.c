/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:43:19 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/19 19:53:52 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	isborder(t_game *game, int i)
{
	if (i < game->width
		|| i > (game->width + 1) * (game->height - 1)
		|| i % (game->width + 1) == 0
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
	{
		free(game->fber);
		printf("map content is invalid\n");
		exit(0);
		// root_destroy(game, "map content is invalid", 0);
	}
}

void	map_validate(t_game *game)
{
	int				i;

	i = -1;
	while (game->fber[++i] != 0)
	{
		if (game->fber[i] == '\n')
			continue ;
		if (isborder(game, i))
		{
			if (game->fber[i] != '1')
			{
				free(game->fber);
				printf("map isn't surrounded by walls\n");
				exit(0);
				// root_destroy(game, "map isn't surrounded by walls", 0);
			}
		}
		else
			isvalid(game, i);
	}
	if (game->count_player != 1
		|| game->count_exit != 1
		|| game->count_coll < 1)
	{
		free(game->fber);
		printf("map configuration is invalid\n");
		exit(0);
		// root_destroy(game, "map configuration is invalid", 0);
	}
}
