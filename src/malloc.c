/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:48:00 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/06 18:46:32 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <stddef.h>
#include "malloc.h"

#include <stdio.h>

extern t_memory		g_memory;

static void	allocating_memory(size_t size)
{
	size_t		size_to_allocate;

	size_to_allocate = get_size_to_allocate(size);
	chunk_list = mmap(NULL, size_to_allocate, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);

}

void	*malloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		return (NULL);

	ptr = NULL;
	printf("%p - %zu\n", &g_memory, g_memory.space_left);
	if (g_memory.space_left < size)
		allocating_memory(size);

	return (ptr);
}
