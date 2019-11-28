/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:51:08 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/07 22:10:07 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int dst_len;
	int i;

	i = 0;
	dst_len = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[dst_len] = s2[i];
		dst_len++;
		i++;
	}
	s1[dst_len] = '\0';
	return (s1);
}
