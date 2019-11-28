/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <rvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 23:49:38 by rvalenti          #+#    #+#             */
/*   Updated: 2018/11/10 04:34:12 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmplf;
	t_list *dst;
	t_list *tmpdst;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmplf = (*f)(lst);
	if (!(dst = ft_lstnew(tmplf->content, tmplf->content_size)))
		return (NULL);
	tmpdst = dst;
	lst = lst->next;
	while (lst != NULL)
	{
		tmplf = (*f)(lst);
		if (!(tmpdst->next = ft_lstnew(tmplf->content, tmplf->content_size)))
			return (NULL);
		tmpdst = tmpdst->next;
		lst = lst->next;
	}
	return (dst);
}
