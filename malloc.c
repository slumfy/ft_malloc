/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:54:08 by rvalenti          #+#    #+#             */
/*   Updated: 2019/11/29 09:28:39 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void *ret_zone(void *zone, t_type type)
{
	if (type == E_TINY)
		return ((void*)zone + sizeof(t_zone));
	else if (type == E_SMALL)
		return ((void*)zone + sizeof(t_zone));
	else
		return ((void*)zone + sizeof(t_zone));

}

static void set_page_to_env(void *map, t_type type)
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
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = map;
		tmp->next->previous = tmp;
	}
	else
		if (type == E_TINY)
			g_env.tiny = map;
		else if (type == E_SMALL)
			g_env.small = map;
		else
			g_env.large = map;
}

static size_t get_size(t_type type, size_t size)
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

static void	create_page(t_type type, size_t size)
{
	void *map;
	t_page page;
	t_zone zone;
	size_t page_size;

	page_size = get_size(type,size);
	zone.status = 0;
	zone.size = page_size;
	zone.next = NULL;
	page.size = page_size;
	page.previous = NULL;
	page.next = NULL;
	map = mmap(NULL,page.size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	page.zone = (map + sizeof(t_page));
	ft_memcpy(map, &page, sizeof(t_page));
	ft_memcpy((map + sizeof(t_page)), &zone, sizeof(t_zone));
	set_page_to_env(map, type);
}

static t_page *check_env(t_type type, size_t size)
{
	if (type == E_TINY)
	{
		if(!g_env.tiny)
			create_page(type, size);
		return (g_env.tiny);
	}			
	else if (type == E_SMALL)
	{
		if(!g_env.small)			
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

static t_zone *create_zone(t_zone *zone, size_t size)
{
	t_zone new_zone;
	void *addr;

	addr = (void*)zone + sizeof(t_zone) + size;
	new_zone.status = 0;
	new_zone.size = zone->size - size;
	new_zone.next = zone->next;
	zone->status = 1;
	zone->size = size;
	ft_memcpy(addr, &new_zone, sizeof(t_zone));
	zone->next = addr;
	return (zone);
}

static void *check_mem(t_type type, size_t size)
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
	create_page(type,size);
	return (check_mem(type,size));
}

void	*malloc(size_t size)
{
	t_type type;
	void *zone;

	if ((type = get_type(size)) == E_ERROR)
		return (NULL);
	zone = check_mem(type,size);
	zone = ret_zone(zone,type);
	return (zone);
}
