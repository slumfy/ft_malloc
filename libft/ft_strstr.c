/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 02:20:53 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/08 02:35:25 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	size_t	i;

	str = (char*)haystack;
	if (needle[0] == '\0')
		return (str);
	while (*str)
	{
		i = 0;
		while (str[i] == needle[i])
		{
			if (needle[i + 1] == '\0')
				return (str);
			i++;
		}
		str++;
	}
	return (NULL);
}
