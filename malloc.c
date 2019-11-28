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

static void *ret_zone(t_type type)
{
	if (type == E_TINY)
		return (g_env.tiny + sizeof(t_page));
	else if (type == E_TINY)
		return (g_env.small + sizeof(t_page));
	else
		return (g_env.large + sizeof(t_page));

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

static void	create_page(t_type type, size_t size)
{
	void *map;
	t_page page;

	page.type = type;
	page.size = size + sizeof(t_page) + 1;
	page.next = NULL;
	page.zone = NULL;
	map = mmap(NULL,page.size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	ft_memcpy(map, &page, sizeof(t_page));
	g_env.tiny = map;
	set_page_to_env(map, type);
}


void	*malloc(size_t size)
{
	t_type type;

	if ((type = get_type(size)) == E_ERROR)
		return (NULL);
	printf("%d\n", type);
	create_page(type, size);
	return (ret_zone(type));
}
