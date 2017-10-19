/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:42:20 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/19 18:08:21 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	copy_content(void **dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_char;
	char	*src_char;

	dst_char = (char*)*dst;
	src_char = (char*)src;
	i = 0;
	while (i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
}

void	*realloc(void *ptr, size_t size)
{
	t_chunk		*to_realloc;
	t_chunk		*tmp;
	size_t		size_to_allocate;

	if (!ptr)
		return (malloc(size));
	if (!(to_realloc = find_chunk(ptr)))
		return (NULL);
	size_to_allocate = (!size ? 1 : size);
	if (size == 0 || to_realloc->size < size)
	{
		tmp = to_realloc;
		if ((to_realloc = malloc(size_to_allocate)))
			copy_content((void**)&to_realloc, tmp + 1, tmp->size);
		free(ptr);
		tmp = NULL;
	}
	return (to_realloc);
}
