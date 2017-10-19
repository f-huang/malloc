/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_chunk_in_memory_stack.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:03:29 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/19 18:07:31 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_chunk	*find_chunk_in_memory_stack(t_chunk *list, void *ptr)
{
	t_chunk	*iterator;

	iterator = list;
	while (ptr && iterator)
	{
		if (iterator + 1 == ptr)
			return (iterator);
		iterator = iterator->next;
	}
	return (NULL);
}
