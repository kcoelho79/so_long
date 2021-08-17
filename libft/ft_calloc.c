/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:09:15 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/05/28 17:33:56 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alc;
	size_t	tot_size;

	tot_size = (count * size);
	alc = malloc(tot_size);
	if (alc == NULL)
		return (NULL);
	ft_bzero(alc, tot_size);
	return (alc);
}
