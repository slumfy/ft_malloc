/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:54:23 by rvalenti          #+#    #+#             */
/*   Updated: 2019/11/29 11:15:47 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int	check_loop(t_page *page, t_zone *zone)
{
	t_zone *tmp;

	while (page)
	{
		tmp = page->zone;
		while (tmp)
		{
			if (tmp == zone)
				return (0);
			tmp = tmp->next;
		}
		page = page->next;
	}
	return (1);
}

int	check_is_zone(t_zone *zone)
{
	t_page *page;

	page = g_env.tiny;
	if (check_loop(page, zone) == 0)
		return (0);
	page = g_env.small;
	if (check_loop(page, zone) == 0)
		return (0);
	page = g_env.large;
	if (check_loop(page, zone) == 0)
		return (0);
	return (1);
}

void	*merge_zone(t_zone *zone, size_t size)
{
	size_t diff;

	diff = size - zone->size;
	zone->next->size = zone->next->size - diff;
	ft_memcpy((zone->next + diff), zone->next, sizeof(t_zone));
	zone->size = size;
	zone->next = (zone->next + diff);
	return (zone + sizeof(t_zone));
}


void	*get_new_alloc(void *ptr, t_zone *zone, size_t size)
{	
	void	*addr;

	addr = NULL;
	if (zone->next->status == 0 && get_type(size) != E_LARGE)
	{
		if ((zone->size + zone->next->size) >= (size + sizeof(t_zone) + 1))
			addr = merge_zone(zone, size);
		addr = ptr;
	}
	else
	{
		addr = malloc(size);
		ft_memcpy(addr , ptr, zone->size);
		free(ptr);
	}
	return (addr);
}

void	*realloc(void *ptr, size_t size)
{
	t_zone	*zone;
	void	*addr;

	if (ptr == NULL)
		return(malloc(size));
	if (ptr && size == 0)
		free(ptr);
	zone = ptr - sizeof(t_zone);
	if (check_is_zone(zone))
		return (NULL);
	if (zone->size >= size)
		return (NULL);
	addr = get_new_alloc(ptr, zone, size);
	return (addr);
}
