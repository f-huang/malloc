/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 12:14:41 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/13 13:17:33 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void	*g_memory[3];
#include <stdio.h>
static void chunk_link(t_chunk **chunk_list, void **ptr)
{
	t_chunk		*iterator;
	int			i;

	iterator = get_last_chunk(*chunk_list);
	if (!iterator)
	{
		*chunk_list = *ptr;
		iterator = *chunk_list;
	}
	else
		iterator->next = *ptr;
	i = 0;
	while (i < 100)
	{
		iterator->next = (t_chunk*)((unsigned char*)iterator +\
							iterator->type + sizeof(t_chunk));
		iterator->next->size = 0;
		iterator->next->type = iterator->type;
		iterator->next->is_used = 0;
		iterator->next->next = NULL;
		iterator = iterator->next;
		++i;
	}
}

static void	chunk_add_single(t_chunk **chunk_list, void **ptr)
{
	t_chunk		*last_chunk;

	last_chunk = get_last_chunk(*chunk_list);
	if (!last_chunk)
	{
		*chunk_list = *ptr;
	}
	else
	{
		last_chunk->next = *ptr;
		last_chunk->next->is_used = 0;
		last_chunk->next->next = NULL;
	}
}

void	chunk_add(void *ptr, size_t size)
{
	enum e_type_index	index;
	enum e_chunk_type	type;

	type = get_chunk_type(size);
	index = get_type_index(type);
	((t_chunk*)ptr)->size = size;
	((t_chunk*)ptr)->type = type;
	((t_chunk*)ptr)->is_used = 0;
	((t_chunk*)ptr)->next = NULL;
	if (size > SMALL)
		chunk_add_single((t_chunk**)&g_memory[index], &ptr);
	if (size == TINY || size == SMALL)
		chunk_link((t_chunk**)&g_memory[index], &ptr);
}
