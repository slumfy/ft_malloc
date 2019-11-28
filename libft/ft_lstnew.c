/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:27:57 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/11 05:35:32 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list) * content_size)))
		return (NULL);
	if (content == NULL)
	{
		content_size = 0;
		new->content_size = content_size;
		new->content = (void*)content;
		new->next = NULL;
	}
	else
	{
		if (!(new->content = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}
