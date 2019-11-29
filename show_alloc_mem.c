/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 03:25:45 by rvalenti          #+#    #+#             */
/*   Updated: 2019/11/29 10:02:34 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_put_size_t(size_t size)
{
	size_t	nb;

	nb = size;
	if (nb >= 10)
	{
		ft_put_size_t(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar(nb + '0');
}

void	print_addr(uint64_t nb)
{
	char	hex_revert[16];
	int		hex[16];
	int		i;

	ft_bzero(hex_revert, 16);
	ft_bzero(hex, 16);
	i = 0;
	while (nb)
	{
		hex[i] = nb % 16;
		if (hex[i] >= 10)
			hex_revert[i] = hex[i] + 'A' - 10;
		else
			hex_revert[i] = hex[i] + '0';
		nb /= 16;
		i++;
	}
	ft_putstr("0x");
	while (i >= 0)
	{
		ft_putchar(hex_revert[i]);
		i--;
	}
}

static size_t	print_page(t_page *page)
{
	t_page *tmpage;
	t_zone *tmp;
	size_t total;

	total = 0;
	tmpage = page;
	while (page)
	{
		tmp = page->zone;
		while (tmp)
		{
			if (tmp->status)
			{
				total = total + tmp->size;
				print_addr((uint64_t)(tmp + sizeof(t_zone)));
				write(1, " - ", 3);
				print_addr((uint64_t)((void*)(tmp + sizeof(t_zone)) + tmp->size));
				write(1, " : ", 3);
				ft_put_size_t(tmp->size);
				write(1, " octets\n", 8);
			}
			tmp = tmp->next;
		}
		page = page->next;
	}
	return (total);
}

void		show_alloc_mem(void)
{
	t_page *page;
	size_t total;

	total = 0;
	if (g_env.tiny)
	{
		page = g_env.tiny;
		write(1, "TINY : ", 7);
		print_addr((uint64_t)g_env.tiny);
		write(1,"\n",1);
		total += print_page(page);
	}
	if (g_env.small)
	{
		page = g_env.small;
		write(1, "SMALL : ", 7);
		print_addr((uint64_t)g_env.tiny);
		write(1,"\n",1);
		total += print_page(page);
	}
	if (g_env.large)
	{
		page = g_env.large;
		write(1, "LARGE : ", 7);
		print_addr((uint64_t)g_env.tiny);
		write(1,"\n",1);
		total += print_page(page);
	}
	write(1, "Total : ", 8);
	ft_put_size_t(total);
	write(1," octets\n", 8);
}
