/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 18:47:31 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/09 22:59:24 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include<stdio.h>
void	chunk_add(void *ptr, size_t size, enum e_chunk_type type)
{
	if (!ptr)
		return ;
	if (g_memory.list_head == NULL)
	{
		g_memory.list_head = (t_chunk*)ptr;
		g_memory.list_head->next = NULL;
	}
	else
		g_memory.list_tail->next = (t_chunk*)ptr;
	g_memory.list_tail = (t_chunk*)ptr;
	g_memory.list_tail->size = size;
	g_memory.list_tail->is_used = 0;
	g_memory.list_tail->type = type;
	g_memory.list_tail->next = NULL;
	// printf("------------Type = %i   -    %p\n", type, g_memory.list_tail);
}
