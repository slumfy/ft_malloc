/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <rvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:05:27 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/09 05:21:31 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		d[n] = (*f)(s[n]);
		n++;
	}
	d[n] = '\0';
	return (d);
}
