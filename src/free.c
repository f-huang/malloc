/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:43:14 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/19 18:08:40 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void		*g_memory[3];

void	free(void *ptr)
{
	t_chunk	*to_free;

	if (!ptr)
		return ;
	to_free = find_chunk(ptr);
	if (to_free)
	{
		to_free->is_used = 0;
		to_free->size = 0;
		if (to_free->type == LARGE)
		{
			chunk_remove((t_chunk**)&g_memory[iLARGE], to_free);
		}
	}
}
