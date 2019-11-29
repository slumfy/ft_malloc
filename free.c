/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:54:17 by rvalenti          #+#    #+#             */
/*   Updated: 2019/11/29 09:54:20 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void		check_page(t_page *page, t_type type)
{
	t_zone *zone;
	t_page *tmp;

	tmp = page;
	zone = tmp->zone;
	while (zone)
	{
		if (zone->status == 1)
			return ;
		zone = zone->next;
	}
	if (page->previous)
	{
		page->previous->next = page->next;
	}
	else
	{
		if (type == E_TINY)
			g_env.tiny = g_env.tiny->next;
		else if (type == E_SMALL)
			g_env.small = g_env.small->next;
		else
			g_env.large = g_env.large->next;
	}
	munmap(tmp, tmp->size);
}

static t_page	*get_page_type(t_type type)
{
	if (type == E_TINY)
		return (g_env.tiny);
	else if (type == E_SMALL)
		return (g_env.small);
	else
		return (g_env.large);
}

static t_page	*check_zone(t_zone *zone, t_type type)
{
	t_page *page;
	t_zone *tmp;

	page = get_page_type(type);
	while (page)
	{
		tmp = page->zone;
		while (tmp)
		{
			if (tmp == zone)
			{
				break ;
			}
			tmp = tmp->next;
		}
		if (tmp == zone)
			break ;
		page = page->next;
	}
	zone->status = 0;
	return (page);
}

void			free(void *ptr)
{
	t_zone *zone;
	t_page *page;
	t_type type;

	if (ptr == NULL)
		return ;
	zone = ptr - sizeof(t_zone);
	if (check_is_zone(zone))
		return ;
	type = get_type(zone->size);
	page = check_zone(zone, type);
	if (page)
		check_page(page, type);
}
