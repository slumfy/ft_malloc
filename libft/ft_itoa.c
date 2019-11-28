/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 01:10:40 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/10 13:38:08 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	long long	nbr;
	char		*dst;
	size_t		count;

	nbr = (long long)n;
	count = ft_nbrlen(nbr);
	if (!(dst = (char*)malloc(sizeof(char) * count + 1)))
		return (NULL);
	dst[count] = '\0';
	if (n == 0)
		dst[0] = '0';
	if (nbr < 0)
	{
		dst[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		dst[count - 1] = (nbr % 10) + '0';
		nbr /= 10;
		count--;
	}
	return (dst);
}
