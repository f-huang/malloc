/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:05:12 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/13 10:45:47 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>
t_chunk		*find_chunk(t_chunk *list, void *ptr)
{
	t_chunk	*iterator;

	iterator = list;
	while (iterator)
	{
		if (iterator + 1 == ptr)
			return (iterator);
		iterator = iterator->next;
	}
	return (NULL);
}
