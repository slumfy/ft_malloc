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

void	*merge_zone(t_zone *zone, size_t size)
{
	size_t diff;

	diff = size - zone->size;
	zone->next->size = zone->next->size - diff;
	ft_memcpy((zone->next + diff), zone->next, sizeof(t_zone));
	zone->size = size;
	return (zone);
}


void	*get_new_alloc(t_zone *zone, size_t size)
{	
	void	*addr;

	if (zone->next->status == 0)
	{
		if (zone->size + zone->next->size >= size + sizeof(t_zone) + 1)
			addr = merge_zone(zone, size);
	}
	else
	{
		addr = malloc(size);
		ft_memcpy(addr , (zone + sizeof(t_zone)), zone->size);
		free(zone + sizeof(t_zone));
		return (addr);
	}
	return (NULL);
}

void	*realloc(void *ptr, size_t size)
{
	t_zone	*zone;
	void	*addr;

	zone = ptr - sizeof(t_zone);

	if (ptr == NULL)
		return(malloc(size));
	if (ptr && size == 0)
		free(ptr);
	if (zone->size >= size)
		return (NULL);
	addr = get_new_alloc(zone, size);
	return (addr);
}
