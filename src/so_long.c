/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:44:04 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/17 16:44:26 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

static void get_map_dimension(t_game *game)
{
	game->height = 0;
	game->width = 0;
	while (*game->fber != '\0')
	{
		if (*game->fber == '\n')
			game->height++;
		if (game->height == 0)
			game->width++;
		game->fber++;
	}
}

static void	read_fber(int f, t_game *game)
{
	char	*buff;
	int		b;
	char	*swp;

	buff = malloc(sizeof(char *) * 1);
	b = read(f, buff, 1);
	game->fber = ft_calloc(1, 1);
	while (b > 0)
	{
		buff[b] = '\0';
		swp = ft_strjoin(game->fber, buff);
		free(game->fber);
		game->fber = swp;
		b = read(f, buff, 1);
	}
	free(buff);
}

void	texture_load(t_game *game, t_img **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	(*img)->width = width;
	(*img)->height = height;
}

void	windows_init(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width * 40, game->height * 40, "So_long");
	game->mlx_img = mlx_new_image(game->mlx, game->width * 40, game->height *40);
	texture_load(game, &game->sprite->player, "./img/player.xpm");
	texture_load(game, &game->sprite->exit, "./img/helicopter.xpm");
	texture_load(game, &game->sprite->coll, "./img/gas.xpm");
	texture_load(game, &game->sprite->wall, "./img/wall.xpm");
	texture_load(game, &game->sprite->ground, "./img/sand.xpm");
}

void	map_init(t_game	*game)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = -1;
	game->map = (int **)malloc(sizeof(int *) * game->height);
	while (++j < game->height)
	{
		game->map[j] = (int *)malloc(sizeof(int) * game->width);
		i = 0;
		while (i < game->width)
		{
			game->map[j][i++] = game->fber[k++] - 48;
		}
		k++;
	}
}

void	game_init(t_game *game)
{
	game->sprite = (t_sprite *)malloc(sizeof(t_sprite));
	game->sprite->player = 0;
	game->sprite->exit = 0;
	game->sprite->coll = 0;
	game->sprite->wall = 0;
	game->sprite->ground = 0;
	get_map_dimension(game);
	map_init(game);
	windows_init(game);
	
}

int	main(int argc, char *argv[])
{
	int		f;
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (argc != 2)
		printf("error: missed arguments");
	f = open(argv[1], O_RDONLY);
	if (f < 0)
		perror("erro openning file");
	read_fber(f, game);
	close(f);
	printf("%s\n", game->fber);
	game_init(game);
	//render(game)
	mlx_loop(game->mlx);
}
