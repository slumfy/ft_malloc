/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:54:08 by rvalenti          #+#    #+#             */
/*   Updated: 2019/11/26 21:25:18 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void check_empty(t_page *page, size_t size)
{
	t_page *tmpage;
	t_zone *tmzone;

	tmpage = page;
	while (tmpage)
	{
		tmzone = tmpage->zone;
		while (tmzone)
		{
			if (tmpzone->size >= size)
				break ;
			tmzone = tmzone->next;
		}
		tmppage = tmpage->next;
	}

}

static void creat_zone(size_t size ,t_env env)
{
	t_zone zone;

	zone.status = 1;
	zone.size = size;
	zone.next = NULL;
	
}

static void creat_page(size_t size,t_env env, int type)
{
	void	*addr;
	t_page	page;

	addr = mmap(0, size,PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	page.type = type;
	page.size = size;
	page.zone = NULL;
	page.next = NULL;
	ft_memcpy(addr, &page, sizeof(t_page));
	env->tiny = addr;
}

void	*malloc(size_t size)
{
	static t_env env;
	if (size <= 0)
		return (NULL);
	creat_page(size * 100, env, 1);
	return 	
}
