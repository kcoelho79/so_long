/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:53:05 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/23 10:21:35 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <mlx_int.h>
# include "libft.h"
# include <errno.h>
# include <fcntl.h>

typedef struct s_coord
{
	int		x;
	int		y;
}		t_coord;

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
	t_coord		player;
	int			count_player;
	t_coord		exit;
	int			count_exit;
	t_coord		*coll;
	int			count_coll;
	t_sprite	*sprite;
	int			player_up;
	int			player_down;
	int			player_left;
	int			player_right;
	int			player_coll;
	int			move_count;
}			t_game;

void			validate_args(int argc);
void			validate_fd(int fd);
void			validate_isber(char *file);

int				start(t_game *game, char *fileber);
void			map_init(t_game	*game);

void			map_validate(t_game *game);
void			windows_init(t_game *game);

void			render(t_game *game);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);

int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				destroy_hook(int keycode, t_game *game);

void			move_up(t_game *game, int x, int y);
void			move_down(t_game *game, int x, int y);
void			move_left(t_game *game, int x, int y);
void			move_right(t_game *game, int x, int y);

void			update(t_game *game);
void			game_destroy(t_game *game);
void			end_game(t_game *game);

void			error(t_game *game, char *error, int numerror);

#endif