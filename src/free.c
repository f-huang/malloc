/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:43:14 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/13 13:18:15 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "malloc.h"
#include <stdio.h>
extern void		*g_memory[3];

void	free(void *ptr)
{
	t_chunk	*to_free;

	if (!ptr)
		return ;
	if (!(to_free = find_chunk(g_memory[iLARGE], ptr)))
		if (!(to_free = find_chunk(g_memory[iSMALL], ptr)))
			to_free = find_chunk(g_memory[iTINY], ptr);
	if (to_free)
	{
		// printf("FREEED --> %p (%lu)\n", to_free, to_free ? to_free->size : 0);
		to_free->is_used = 0;
		to_free->size = 0;
		if (to_free->size > SMALL)
		{
			chunk_remove((t_chunk**)&g_memory[iLARGE], to_free);
		}
	}
}
