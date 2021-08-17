/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:30:36 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/05/28 17:35:09 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_s;
	size_t	size_s;
	size_t	i;

	size_s = ft_strlen(s1) + 1;
	new_s = malloc(size_s * sizeof(char));
	i = 0;
	if (new_s == NULL)
		return (NULL);
	ft_memcpy(new_s, s1, size_s);
	return (new_s);
}
