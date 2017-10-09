/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:36:07 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/09 23:38:31 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "malloc.h"

extern t_memory	g_memory;
#include <stdio.h>
void	*allocate_memory(size_t size)
{
	void	*ptr;
	size_t	size_to_allocate;

printf("------ allocate_memory: %zu -------\n", size);
	size_to_allocate = get_size_to_allocate(sizeof(t_chunk) + size);
	if (size_to_allocate <= 0)
		return (NULL);
	ptr = mmap(NULL, size_to_allocate,\
		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
	if (ptr)
		g_memory.space_left += size_to_allocate;
	chunk_add(ptr, size_to_allocate, get_chunk_type(size));
	return (ptr);
}
