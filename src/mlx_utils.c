/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 22:15:36 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/08/24 18:43:52 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	/* usa se o offset, para pegar o endereco em mem. da cor
	 * img->data tem o inicio do endereco do 1pixel da imagem
	 usa a matematica de ponteiro, para ver a posicao da coor pixel +
	 offsetda cor, e entao se obtem a cor do pixel da imagem
	 */
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;
// target é um ponteiro, que recebe o endereco do pixel 
	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	// atribuiçao da cor, no enderço da vat target
	*(unsigned int *)target = color;
}

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}
