/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chunk_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:12:46 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/13 10:49:35 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

void	print_chunk_list(t_chunk *list)
{
	t_chunk	*iterator = list;

	while (iterator)
	{
		if (iterator->is_used || iterator->size > SMALL)
			printf("{%p} ptr = %p (%zu)\n", iterator, iterator + 1, iterator ? iterator->size : 0);
		iterator = iterator->next;
	}
}
