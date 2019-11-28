/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 02:37:08 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/10 13:13:09 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *search, const char *find, size_t n)
{
	char	*str;
	size_t	i;

	str = (char*)search;
	if (find[0] == '\0')
		return (str);
	while (*str && n > 0)
	{
		i = 0;
		while (str[i] == find[i] && n > 0 && str[i])
		{
			if (find[i + 1] == '\0')
				return (str);
			i++;
			n--;
		}
		n += i;
		str++;
		n--;
	}
	return (NULL);
}
