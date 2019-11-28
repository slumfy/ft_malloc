/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:12:36 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/09 05:29:50 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	n;
	char	*d;

	if (s == 0)
		return (NULL);
	if (!(d = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	n = 0;
	while (s[n])
	{
		d[n] = (*f)(n, s[n]);
		n++;
	}
	d[n] = '\0';
	return (d);
}
