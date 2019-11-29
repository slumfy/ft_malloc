/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 09:54:33 by rvalenti          #+#    #+#             */
/*   Updated: 2019/11/29 10:18:05 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "ft_malloc.h"

int		main(void)
{
	char *test;
	char *test2;
	char *test3;
	char *test4;
	char *test5;

	test = (char*)malloc(1);
	test2 = (char*)malloc(20);
	test3 = (char*)malloc(1000);
	test4 = (char*)malloc(4096);
	test5 = (char*)malloc(4096);
	show_alloc_mem();
	free(test2);
	free(test3);
	free(test5);
	show_alloc_mem();
}
