/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:59:59 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/05/27 16:45:57 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_digits(int n)
{
	size_t	count;

	if (n >= 0)
		count = 1;
	else
		count = 2;
	while (n / 10)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	unsigned int	dig_count;
	char			*str;
	unsigned int	signal;

	nbr = (unsigned int)n;
	signal = 0;
	if (n < 0)
	{
		nbr *= -1;
		signal = 1;
	}
	dig_count = ft_count_digits(n);
	str = malloc(sizeof(char) * (dig_count + 1));
	if (str == NULL)
		return (NULL);
	str[dig_count] = '\0';
	while (dig_count--)
	{
		str[dig_count] = '0' + (nbr % 10);
		nbr = nbr / 10;
	}
	if (signal == 1)
		str[0] = '-';
	return (str);
}
