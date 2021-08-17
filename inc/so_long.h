/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:53:05 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/17 16:18:52 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <mlx_int.h>
# include "libft.h"
# include <errno.h>
# include <fcntl.h>

typedef struct s_sprite
{
	t_img		*player;
	t_img		*exit;
	t_img		*coll;
	t_img		*wall;
	t_img		*ground;
}		t_sprite;

typedef struct s_game
{
	char		*fber;
	int			height;
	int			width;
	int			**map;
	void		*mlx;
	void		*mlx_win;
	t_img		*mlx_img;
	t_sprite	*sprite;
}			t_game;

#endif