/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:48:00 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/09 23:38:12 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

extern t_memory		g_memory;

void	*malloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		return (NULL);
	if (g_memory.space_left < size)
		allocate_memory(size);
	ptr = chunk_split(size);
	if (ptr)
		g_memory.space_left -= size;
	return (ptr);
}
