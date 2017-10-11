/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:31:48 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/10 21:52:09 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

#include <stdio.h>
extern t_memory	g_memory;

static void	print_memory_depending_on_type(enum e_chunk_type type)
{
	t_chunk		*iterator;
	int			first;
	int			address;

	first = 1;
	iterator = g_memory.list_head;
	while (iterator)
	{
		if (iterator->type == type && iterator->is_used)
		{
			if (first && !(first = 0))
				printf("%s : %p\n", get_type_name(type), iterator);
			address = ((iterator + iterator->size) - iterator) / 24;
			printf("%p - %p : %zu octets\n", iterator, iterator + address, iterator->size);
		}
		iterator = iterator->next;
	}
}

void	show_alloc_mem(void)
{
	print_memory_depending_on_type(TINY);
	print_memory_depending_on_type(SMALL);
	print_memory_depending_on_type(LARGE);
}
