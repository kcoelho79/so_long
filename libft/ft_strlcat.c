/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:08:49 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/05/28 17:22:59 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	i;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	i = 0;
	if (size_dst < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && size_dst + i < dstsize - 1)
		{
			dst[size_dst + i] = src[i];
			i++;
		}
		dst[size_dst + i] = '\0';
	}
	if (size_dst >= dstsize)
		size_dst = dstsize;
	return (size_dst + size_src);
}
