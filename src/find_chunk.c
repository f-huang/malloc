/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:05:12 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/12 17:07:12 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>
t_chunk		*find_chunk(t_chunk *list, t_chunk *needle)
{
	t_chunk	*iterator;

	iterator = list;
	while (iterator)
	{
		if (iterator == needle)
			return (iterator);
		iterator = iterator->next;
	}
	return (iterator == needle ? iterator : NULL);
}
