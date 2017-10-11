/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:17:08 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/10 21:48:05 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

extern t_memory	g_memory;

static t_chunk	*find_unused_chunk(t_chunk *list, size_t size)
{
	t_chunk				*iterator;
	enum e_chunk_type	type;

	type = get_chunk_type(size);
	iterator = list;
	while (iterator)
	{
		if (!iterator->is_used && iterator->size >= size\
			&& ((iterator->type == LARGE && type == LARGE) ||\
			(iterator->type != LARGE && type != LARGE)))
			return (iterator);
		iterator = iterator->next;
	}
	return (allocate_memory(size));
}

void			*chunk_split(size_t size)
{
	t_chunk				*unused_chunk;
	size_t				remaining_space;

	if (!g_memory.list_head)
		return (NULL);
	unused_chunk = find_unused_chunk(g_memory.list_head, size);
	if (!unused_chunk)
		return (NULL);
	if ((remaining_space = unused_chunk->size - size))
	{
		chunk_add(unused_chunk + 1, remaining_space, unused_chunk->type);
	}
	unused_chunk->size = size;
	unused_chunk->type = get_chunk_type(size);
	unused_chunk->is_used = 1;
	printf("unused : %p\nunused + 1 : %p\nunused next: %p\nis_used : %p\n----------------------\n", unused_chunk, unused_chunk + 1, unused_chunk->next, &unused_chunk->is_used);
	return (unused_chunk);
}
