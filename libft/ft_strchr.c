/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 22:27:35 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/16 00:20:54 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *src;
	char value;

	src = (char*)s;
	value = (char)c;
	while (*src != '\0' && *src != value)
		src++;
	if (*src == value)
		return (src);
	return (NULL);
}
