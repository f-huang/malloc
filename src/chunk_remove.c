/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 19:00:58 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/09 20:52:25 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "malloc.h"

extern t_memory	g_memory;

static void	update_list_links(t_chunk **prev)
{
	if (!*prev)
		g_memory.list_head = g_memory.list_head->next;
	else
	{
		(*prev)->next = g_memory.list_head->next;
		if (!g_memory.list_head->next)
			g_memory.list_head = (*prev)->next;
	}
}

void	chunk_remove(t_chunk *to_remove, int should_unmap)
{
	t_chunk		*iterator;
	t_chunk		*prev;

	iterator = g_memory.list_head;
	prev = NULL;
	while (iterator->next)
	{
		if (iterator == to_remove)
		{
			if (should_unmap && to_remove->size > 0)
				munmap(to_remove, to_remove->size);
			update_list_links(&prev);
			to_remove = NULL;
			break ;
		}
		prev = iterator;
		iterator = iterator->next;
	}
}
