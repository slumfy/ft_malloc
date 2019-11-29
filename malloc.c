/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:54:08 by rvalenti          #+#    #+#             */
/*   Updated: 2019/11/26 22:59:52 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_env	g_env = {0,0,0};

static void *ret_zone(void *zone, t_type type)
{
	if (type == E_TINY)
		return (zone + sizeof(t_zone));
	else if (type == E_TINY)
		return (zone + sizeof(t_zone));
	else
		return (zone + sizeof(t_page));

}


static t_type	get_type(size_t size)
{
	t_type type;
	type = E_ERROR;	
	if (size)
	{
		if (size <= SMALL)
			type = E_TINY;
		else if (size < LARGE)
			type = E_SMALL;
		else
			type = E_LARGE;
	}
	return (type);
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
	}
	else
		if (type == E_TINY)
			g_env.tiny = map;
		else if (type == E_SMALL)
			g_env.small = map;
		else
			g_env.large = map;
}

static *t_page check_env(t_type type)
{

}

static void *check_mem(t_type type, size_t size)
{
	t_page *tmpage;
	t_zone *tmzone;

	tmpage = check_env(type);
}

static void	create_page(t_type type, size_t size)
{
	void *map;
	t_page page;
	t_zone zone;

	zone.status = 0;
	zone.size = size + 1;
	zone.next = NULL;
	page.type = type;
	page.size = size + sizeof(t_page) + 1;
	page.next = NULL;
	map = mmap(NULL,page.size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	page.zone = (map + sizeof(t_page));
	ft_memcpy(map, &page, sizeof(t_page));
	ft_memcpy((map + sizeof(t_page)), &zone, sizeof(t_zone));
	set_page_to_env(map, type);
}


void	*malloc(size_t size)
{
	t_type type;
	void *zone;

	if ((type = get_type(size)) == E_ERROR)
		return (NULL);
	zone = check_mem(type,size);
	//create_page(type, size);
	return (zone, ret_zone(type));
}
