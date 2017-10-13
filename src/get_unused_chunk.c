/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unused_chunk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:28:23 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/13 13:17:05 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void		*g_memory[3];

t_chunk	*get_unused_chunk(enum e_chunk_type type, size_t size)
{
	enum e_type_index	i;
	t_chunk				*iterator;

	i = get_type_index(type);
	iterator = (t_chunk*)g_memory[i];
	while (iterator)
	{
		if (!iterator->is_used &&\
			((iterator->type == type && type != LARGE) ||\
			(iterator->size == size)))
			return (iterator);
		iterator = iterator->next;
	}
	return (iterator);
}
