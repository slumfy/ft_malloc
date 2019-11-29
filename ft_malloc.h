/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:32:40 by rvalenti          #+#    #+#             */
/*   Updated: 2019/11/29 08:14:21 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define TINY 512
# define SMALL 1024

# include <stdlib.h>
# include <sys/mman.h>
# include "libft/libft.h"

#include <stdio.h> // debug

typedef enum	e_type
{
	E_TINY,
	E_SMALL,
	E_LARGE,
	E_ERROR
}				t_type;

typedef	struct	s_zone
{
	int				status;
	size_t			size;
	struct s_zone	*next;
}				t_zone;

typedef	struct	s_page
{
	size_t		size;
	struct s_page	*previous;
	struct s_page	*next;
	struct s_zone	*zone;
}				t_page;

typedef struct	s_env
{
	struct s_page	*tiny;
	struct s_page	*small;
	struct s_page	*large;
}				t_env;

t_env				g_env;

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem(void);


t_type get_type(size_t size);
#endif
