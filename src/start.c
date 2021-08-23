/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 09:31:48 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/23 10:28:10 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_init(t_game *game)
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
	game->coll = 0;
	game->move_count = 0;
}

static void	load_map(t_game *game, char *fileber)
{
	int		fd;
	int		b;
	char	buff[1024 + 1];
	char	*swp;

	fd = open(fileber, O_RDONLY);
	validate_fd(fd);
	validate_isber(fileber);
	b = read(fd, buff, 1024);
	game->fber = ft_calloc(1, 1);
	if (!game->fber)
		error(game, "error ft_calloc", errno);
	while (b > 0)
	{
		buff[b] = '\0';
		swp = ft_strjoin(game->fber, buff);
		free(game->fber);
		game->fber = swp;
		b = read(fd, buff, 1);
	}
	close(fd);
}

int	start(t_game *game, char *fileber)
{
	load_map(game, fileber);
	game_init(game);
	map_init(game);
	windows_init(game);
	render(game);
	return (1);
}
