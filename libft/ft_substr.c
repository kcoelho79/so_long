/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:36:37 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/06/04 12:20:56 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;
	size_t	m_size;
	size_t	s_start;

	if (s == NULL)
		return (NULL);
	s_start = start;
	size = ft_strlen(s);
	if (start > size)
	{
		m_size = 1;
		s_start = 0;
	}
	else if (start + len > size)
		m_size = size - start + 1;
	else
		m_size = len + 1;
	sub = malloc(m_size);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + s_start, m_size);
	return (sub);
}
