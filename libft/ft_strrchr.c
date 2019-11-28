/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 01:54:10 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/08 02:17:13 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*src;
	char	value;
	size_t	i;

	src = (char*)s;
	value = (char)c;
	i = ft_strlen(src);
	while (i != 0 && src[i] != value)
		i--;
	if (src[i] == value)
		return (src + i);
	return (NULL);
}
