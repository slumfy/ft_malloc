/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:04:50 by rvalenti          #+#    #+#             */
/*   Updated: 2019/11/29 10:15:44 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		set_page_to_env(void *map, t_type type)
{
	t_page *tmp;

	if (type == E_TINY)
		tmp = g_env.tiny;
	else if (type == E_SMALL)
		tmp = g_env.small;
	else
		tmp = g_env.large;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = map;
		tmp->next->previous = tmp;
	}
	else
	{
		if (type == E_TINY)
			g_env.tiny = map;
		else if (type == E_SMALL)
			g_env.small = map;
		else
			g_env.large = map;
	}
}

void		create_page(t_type type, size_t size)
{
	void	*map;
	t_page	page;
	t_zone	zone;
	size_t	page_size;

	page_size = get_size(type, size);
	zone.status = 0;
	zone.size = page_size;
	zone.next = NULL;
	page.size = page_size;
	page.previous = NULL;
	page.next = NULL;
	map = mmap(NULL, page.size, PROT_READ | PROT_WRITE
			, MAP_ANON | MAP_PRIVATE, -1, 0);
	page.zone = (map + sizeof(t_page));
	ft_memcpy(map, &page, sizeof(t_page));
	ft_memcpy((map + sizeof(t_page)), &zone, sizeof(t_zone));
	set_page_to_env(map, type);
}

t_page		*check_env(t_type type, size_t size)
{
	if (type == E_TINY)
	{
		if (!g_env.tiny)
			create_page(type, size);
		return (g_env.tiny);
	}
	else if (type == E_SMALL)
	{
		if (!g_env.small)
			create_page(type, size);
		return (g_env.small);
	}
	else
	{
		if (!g_env.large)
			create_page(type, size);
		return (g_env.large);
	}
}

t_zone		*create_zone(t_zone *zone, size_t size)
{
	t_zone	new_zone;
	void	*addr;

	addr = (void*)zone + sizeof(t_zone) + size;
	new_zone.status = 0;
	new_zone.size = zone->size - size - sizeof(t_zone);
	new_zone.next = zone->next;
	zone->status = 1;
	zone->size = size;
	ft_memcpy(addr, &new_zone, sizeof(t_zone));
	zone->next = addr;
	return (zone);
}
