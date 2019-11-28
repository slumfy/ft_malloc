/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <rvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:42:00 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/08 00:06:11 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	v;
	unsigned char	*tmp_s;

	tmp_s = (unsigned char*)s;
	v = (unsigned char)c;
	while (n)
	{
		if (*tmp_s == v)
			return (tmp_s);
		n--;
		tmp_s++;
	}
	return (NULL);
}
