/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:48:00 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/13 13:20:59 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>
extern void		*g_memory[3];
void	*malloc(size_t size)
{
	t_chunk				*ptr;
	enum e_chunk_type	type;

	if (size == 0)
		return (NULL);
	ptr = NULL;
	type = get_chunk_type(size);
	if (type == LARGE || !(ptr = get_unused_chunk(type, size)))
		allocate_memory(size);
	if (!ptr)
		ptr = get_unused_chunk(type, size);
	if (ptr)
	{
		ptr->size = size;
		ptr->is_used = 1;
		return (ptr + 1);
	}
	return (NULL);
}
