/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:48:00 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/20 10:10:58 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void				*g_memory[3];
extern pthread_mutex_t	g_mutex;

void	*malloc(size_t size)
{
	t_chunk				*ptr;
	enum e_chunk_type	type;

	if (size == 0)
		return (NULL);
	ptr = NULL;
	pthread_mutex_init(&g_mutex, NULL);
	type = get_chunk_type(size);
	pthread_mutex_lock(&g_mutex);
	if (type == LARGE || !(ptr = get_unused_chunk(type, size)))
		allocate_memory(size);
	if (!ptr)
		ptr = get_unused_chunk(type, size);
	if (ptr)
	{
		ptr->size = size;
		ptr->is_used = 1;
	}
	pthread_mutex_unlock(&g_mutex);
	pthread_mutex_destroy(&g_mutex);
	return (ptr ? ptr + 1 : NULL);
}
