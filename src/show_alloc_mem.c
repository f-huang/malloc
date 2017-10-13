/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:31:48 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/13 13:27:20 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "malloc.h"

extern void		*g_memory[3];

static void	print_memory(enum e_chunk_type type, unsigned long long *total)
{
	int					index;
	t_chunk				*iterator;

	index = get_type_index(type);
	iterator = g_memory[index];
	ft_printf("%s : %p\n", get_type_name(type), iterator);
	while (iterator)
	{
		if (iterator->is_used)
		{
			ft_printf("%p - %p : %zu octet%c\n",\
				iterator + 1,\
				(unsigned char*)iterator + sizeof(t_chunk) + iterator->type,\
				iterator->size,
				iterator->size < 2 ? '\0' : 's'\
			);
			*total += iterator->size;
		}
		iterator = iterator->next;
	}
}

void	show_alloc_mem(void)
{
	unsigned long long	total;

	total = 0;
	print_memory(TINY, &total);
	print_memory(SMALL, &total);
	print_memory(LARGE, &total);

	ft_printf("Total : %llu octet%c\n", total, total < 2 ? '\0' : 's');
}
