/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <rvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:02:11 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/10 13:02:14 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t n;

	n = 0;
	if (s != NULL && (*f) != NULL)
	{
		while (s[n])
		{
			(*f)(n, &s[n]);
			n++;
		}
	}
}
