/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:40:31 by rvalenti          #+#    #+#             */
/*   Updated: 2019/11/29 09:55:21 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_putstr(char const *s)
{
	size_t i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp_dest;
	unsigned int	i;

	tmp = (unsigned char *)src;
	tmp_dest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		tmp_dest[i] = tmp[i];
		i++;
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		((char*)s)[i] = 0;
		i++;
	}
}

t_type	get_type(size_t size)
{
	t_type type;

	type = E_ERROR;
	if (size)
	{
		if (size < TINY)
			type = E_TINY;
		else if (size < SMALL)
			type = E_SMALL;
		else
			type = E_LARGE;
	}
	return (type);
}
