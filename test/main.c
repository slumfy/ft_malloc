/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:52:44 by rvalenti          #+#    #+#             */
/*   Updated: 2020/01/08 19:43:12 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_malloc.h"

int	main(void)
{
	char *ptr;
	ptr = malloc((size_t)-1);
	printf("%s\n",ptr);
	ptr = malloc((size_t)-1000);
	printf("%s\n",ptr);
	return (0);
}
