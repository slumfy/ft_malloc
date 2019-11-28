/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <rvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:55:16 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/07 23:43:02 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp_dest;
	unsigned int	i;
	unsigned char	value;

	value = (unsigned char)c;
	tmp = (unsigned char *)src;
	tmp_dest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		tmp_dest[i] = tmp[i];
		if (tmp[i] == value)
			return ((dest + i + 1));
		i++;
	}
	return (NULL);
}
