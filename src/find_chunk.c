/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:05:12 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/19 18:07:21 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void	*g_memory[3];

t_chunk		*find_chunk(void *ptr)
{
	t_chunk	*found;

	found = NULL;
	if (!(found = find_chunk_in_memory_stack(g_memory[iLARGE], ptr)))
		if (!(found = find_chunk_in_memory_stack(g_memory[iSMALL], ptr)))
			found = find_chunk_in_memory_stack(g_memory[iTINY], ptr);
	return (found);
}
