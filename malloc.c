/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:54:08 by rvalenti          #+#    #+#             */
/*   Updated: 2020/01/08 19:44:52 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		*ret_zone(void *zone, t_type type)
{
	if (type == E_TINY)
		return (zone + sizeof(t_zone));
	else if (type == E_SMALL)
		return (zone + sizeof(t_zone));
	else
		return (zone + sizeof(t_zone));
}

size_t		get_size(t_type type, size_t size)
{
	size_t page_size;
	size_t diff;
	size_t check;

	check = 0;
	diff = 0;
	if (type == E_TINY || type == E_SMALL)
	{
		page_size = (size + sizeof(t_zone)) * 100 + sizeof(t_page);
		if ((diff = page_size % (size_t)getpagesize) != 0)
			page_size = page_size + diff;
		return (page_size);
	}
	else
	{
		check = size + sizeof(t_zone) + sizeof(t_page);
		if (check < size)
			return (0);
		if ((diff = check % (size_t)getpagesize) != 0)
			check = check + diff;
		page_size = check;
		if (page_size < check)
			return (0);
	}
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
			if (tmzone->status == 0 && tmzone->size >= (size))
				return (create_zone(tmzone, size));
			tmzone = tmzone->next;
		}
		tmpage = tmpage->next;
	}
	if ((create_page(type, size) != 0))
		return (NULL);
	return (check_mem(type, size));
}

void		*malloc(size_t size)
{
	t_type	type;
	t_zone	*zone;

	if ((type = get_type(size)) == E_ERROR)
		return (NULL);
	if ((zone = check_mem(type, size)) == NULL)
		return (NULL);
	zone = ret_zone(zone, type);
	return (zone);
}
