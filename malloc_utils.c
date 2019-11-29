/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:40:31 by rvalenti          #+#    #+#             */
/*   Updated: 2019/11/29 08:04:40 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_type	get_type(size_t size)
{
	t_type type;
	type = E_ERROR;
	if (size)
	{
		if (size < TINY)
			type = E_TINY;
		else if (size < SMALL)
			type = E_SMALL;
		else
			type = E_LARGE;
	}
	return (type);
}
