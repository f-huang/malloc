/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chunk_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:12:46 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/12 19:09:56 by fhuang           ###   ########.fr       */
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
			printf("%p (%zu)\n", iterator, iterator ? iterator->size : 0);
		iterator = iterator->next;
	}
}
