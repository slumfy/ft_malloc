/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 03:25:45 by rvalenti          #+#    #+#             */
/*   Updated: 2019/11/29 08:13:47 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		show_alloc_mem(void)
{
	t_page *page;
	t_zone *tmp;
	if(g_env.tiny)
	{
		page = g_env.tiny;
		printf("TINY : %p\n", g_env.tiny);
		while (page)
		{
			tmp = page->zone;
			while (tmp)
			{
				if (tmp->status)
					printf("%p - %p : %zu octets\n",(tmp + sizeof(t_zone)), ((void*)(tmp + sizeof(t_zone))+ tmp->size), tmp->size);
				tmp = tmp->next;
			}	
			page = page->next;
		}
	}

	if(g_env.small)
	{
		page = g_env.small;
		printf("SMALL : %p\n", g_env.small);
		while (page)
		{
			tmp = page->zone;
			while (tmp)
			{
				if (tmp->status)
					printf("%p - %p : %zu octets\n",(tmp + sizeof(t_zone)), ((void*)(tmp + sizeof(t_zone))+ tmp->size), tmp->size);
				tmp = tmp->next;
			}	
			page = page->next;
		}
	}
	if(g_env.large)
	{
		page = g_env.large;
		printf("LARGE : %p\n", g_env.large);
		while (page)
		{
			tmp = page->zone;
			while (tmp)
			{
				if (tmp->status)
					printf("%p - %p : %zu octets\n",(tmp + sizeof(t_zone)), ((void*)(tmp + sizeof(t_zone))+ tmp->size), tmp->size);
				tmp = tmp->next;
			}	
			page = page->next;
		}
	}
}