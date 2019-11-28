/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <rvalenti@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:11:30 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/09 05:27:59 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t i;
	size_t len;

	if (s == 0)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t' || s[len] == '\0')
			&& len > i)
		len--;
	len = len + 1 - i;
	return (ft_strsub(s, i, len));
}
