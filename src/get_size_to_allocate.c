/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_to_allocate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:44:00 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/09 21:21:50 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "malloc.h"

static size_t	get_closest_multiple(size_t number)
{
	size_t	ret;
	size_t	pagesize;

	pagesize = getpagesize();
	if (number % pagesize)
		ret = (number / pagesize + 1) * pagesize;
	else
		ret = number;
	return (ret);
}

size_t	get_size_to_allocate(size_t size)
{
	size_t	total_size;

	total_size = get_chunk_type(size) * 100 * size;
	return (get_closest_multiple(total_size));
}
