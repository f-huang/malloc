/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:37:17 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/12 19:35:09 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "malloc.h"

void	chunk_remove(t_chunk **list, t_chunk *needle)
{
	t_chunk		*iterator;
	t_chunk		*prev;

	prev = NULL;
	iterator = *list;
	while (iterator)
	{
		if (iterator == needle)
		{
			if (prev == NULL)
				*list = iterator->next;
			else
				prev->next = iterator->next;
			munmap(iterator, iterator->size);
			iterator = NULL;
			break ;
		}
		prev = iterator;
		iterator = iterator->next;
	}
}
