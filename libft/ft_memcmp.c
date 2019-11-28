/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:26:18 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/10 13:03:50 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	i = 0;
	tmp_s1 = (unsigned char*)s1;
	tmp_s2 = (unsigned char*)s2;
	if (n)
	{
		if (tmp_s1[i] == '\0' && tmp_s2[i] == '\0')
			return (0);
		while (i < n)
		{
			if (tmp_s1[i] != tmp_s2[i])
				return (tmp_s1[i] - tmp_s2[i]);
			i++;
		}
	}
	return (0);
}
