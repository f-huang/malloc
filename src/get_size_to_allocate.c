/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_to_allocate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:44:00 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/12 19:20:21 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "malloc.h"

static size_t	get_closest_multiple(size_t number)
{
	size_t	pagesize;

	pagesize = getpagesize();
	while (number % pagesize)
		++number;
	return (number);
}

size_t	get_size_to_allocate(size_t size)
{
	enum e_chunk_type	type;
	size_t				total_size;

	type = get_chunk_type(size);
	total_size = (type == LARGE ?\
		size + sizeof(t_chunk) :\
		(type + sizeof(t_chunk)) * 100);
	return (get_closest_multiple(total_size));
}
