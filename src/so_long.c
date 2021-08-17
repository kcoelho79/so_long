/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:44:04 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/17 14:35:21 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

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
	// close(f);
	free(buff);
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
	printf("%s\n", game->fber);
// 	map_init(f);
}
