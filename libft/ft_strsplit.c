/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <rvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 22:23:39 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/11 05:45:12 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_fill_tab(char const *s, char c, char **tab, int count)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	while (++j < count && s[i] != '\0')
	{
		k = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i + k] != c && s[i + k] != '\0')
			k++;
		if (!(tab[j] = ft_strsub(s, i, k)))
		{
			ft_freetab((void***)(&tab));
			return (tab);
		}
		i += k;
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dst;
	int		count;

	if (s == 0)
		return (NULL);
	count = ft_countword(s, c);
	if (!(dst = (char**)malloc(sizeof(char*) * count + 1)))
		return (NULL);
	dst = (ft_fill_tab(s, c, dst, count));
	return (dst);
}
