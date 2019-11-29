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

void	*get_new_alloc(t_zone zone, size_t size)
{
	
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
