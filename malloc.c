/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:54:08 by rvalenti          #+#    #+#             */
/*   Updated: 2019/12/02 10:25:11 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		*ret_zone(void *zone, t_type type)
{
	if (type == E_TINY)
		return ((void*)zone + sizeof(t_zone));
	else if (type == E_SMALL)
		return ((void*)zone + sizeof(t_zone));
	else
		return ((void*)zone + sizeof(t_zone));
}

size_t		get_size(t_type type, size_t size)
{
	size_t page_size;
	size_t diff;

	if (type == E_TINY || type == E_SMALL)
	{
		page_size = (size + sizeof(t_zone)) * 100 + sizeof(t_page);
		if ((diff = page_size % (size_t)getpagesize) != 0)
			page_size = page_size + diff;
		return (page_size);
	}
	else
		page_size = size + sizeof(t_zone) + sizeof(t_page);
	if ((diff = page_size % (size_t)getpagesize) != 0)
		page_size = page_size + diff;
	return (page_size);
}

void		*check_mem(t_type type, size_t size)
{
	t_page *tmpage;
	t_zone *tmzone;

	tmpage = check_env(type, size);
	while (tmpage)
	{
		tmzone = tmpage->zone;
		while (tmzone)
		{
			if (tmzone->status == 1 && type == E_LARGE)
				break ;
			if (tmzone->status == 0)
				if (tmzone->size >= (size + sizeof(t_zone) + 1))
					return (create_zone(tmzone, size));
			tmzone = tmzone->next;
		}
		tmpage = tmpage->next;
	}
	create_page(type, size);
	return (check_mem(type, size));
}

void		*malloc(size_t size)
{
	t_type	type;
	void	*zone;

	if ((type = get_type(size)) == E_ERROR)
		return (NULL);
	zone = check_mem(type, size);
	zone = ret_zone(zone, type);
	return (zone);
}
