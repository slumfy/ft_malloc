/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <rvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 03:36:08 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/10 04:37:29 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_sortint(int *s, size_t len)
{
	size_t i;

	if (s == NULL)
		return (NULL);
	while ((len - 1) > 0)
	{
		i = 0;
		while (i < (len - 1))
		{
			if (s[i] > s[i + 1])
				ft_swap(&s[i], &s[i + 1]);
			i++;
		}
		len--;
	}
	return (s);
}
