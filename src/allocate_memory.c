/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:36:07 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/12 19:18:54 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "malloc.h"

void	*allocate_memory(size_t size)
{
	void				*ptr;
	enum e_chunk_type	type;
	size_t				size_to_allocate;

	size_to_allocate = get_size_to_allocate(size);
	if (size_to_allocate <= 0)
		return (NULL);
	ptr = mmap(NULL, size_to_allocate,\
		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
	if (ptr)
	{
		type = get_chunk_type(size);
		size = (type == LARGE ? size : type);
		chunk_add(ptr, size);
	}
	return (ptr);
}
