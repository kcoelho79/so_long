/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:44:04 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/19 13:07:00 by kde-oliv         ###   ########.fr       */
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

static void	read_fber(int f, t_game *game)
{
	char	buff[1024 + 1];
	int		b;
	char	*swp;

//	buff = malloc(sizeof(char *) * 1);
	b = read(f, buff, 1024);
	game->fber = ft_calloc(1, 1);
	while (b > 0)
	{
		buff[b] = '\0';
		swp = ft_strjoin(game->fber, buff);
		free(game->fber);
		game->fber = swp;
		b = read(f, buff, 1);
	}
	//free(buff);
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

static void	get_coord(t_game *game, int i, int *obj)
{
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
		game->coll[*obj].x = i % (game->width + 1);
		game->coll[*obj].y = i / (game->width + 1);
		game->fber[i] = '0';
		(*obj)++;
	}
}

void	map_init(t_game	*game)
{
	size_t	i;
	int		row;
	int		col;
	int		obj;

	obj = 0;
	i = 0;
	row = -1;
	game->count_coll = 1;
	game->count_exit = 1;
	game->count_player = 1;
	game->map = (int **)malloc(sizeof(int *) * game->height);
	game->coll = (t_coord *)malloc(sizeof(t_coord) * game->count_coll);
	while (++row < game->height)
	{
		game->map[row] = (int *)malloc(sizeof(int) * game->width);
		col = 0;
		while (col < game->width)
		{
			get_coord(game, i, &obj);
			game->map[row][col++] = game->fber[i++];
		}
		i++;
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
	game->player_up = 0;
	game->player_down = 0;
	game->player_left = 0;
	game->player_right = 0;
	get_map_dimension(game);
	map_init(game);
	windows_init(game);
}

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
			if (game->map[y][x] == '1')
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
	game_init(game);
	render(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_win, 3, 1L << 0, key_release, game);
	mlx_loop(game->mlx);
	return (0);
}
