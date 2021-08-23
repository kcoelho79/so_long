/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:06:06 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/23 10:53:36 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_fd(int fd)
{
	if (fd < 0)
	{
		perror("erro openning file");
		exit(1);
	}
}

void	validate_isber(char *file)
{
	int				len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".ber", len) != 0)
	{
		printf("is not format *.ber\n");
		exit(1);
	}
}

void	validate_args(int argc)
{
	if (argc != 2)
	{
		printf("error: missed arguments \n");
		exit (1);
	}
}

void	error(t_game *game, char *msgerror, int numerror)
{
	game_destroy(game);
	printf("\nerror: %s%s\n", msgerror, strerror(numerror));
	exit(0);
}
