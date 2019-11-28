/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <rvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:01:40 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/08 01:04:47 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;
	unsigned char	*tmp_dst;
	unsigned int	i;

	i = 0;
	tmp = (unsigned char*)src;
	tmp_dst = (unsigned char*)dst;
	if (src > dst)
		while (i < len)
		{
			tmp_dst[i] = tmp[i];
			i++;
		}
	else
	{
		while (len)
		{
			tmp_dst[len - 1] = tmp[len - 1];
			len--;
		}
	}
	return (dst);
}
