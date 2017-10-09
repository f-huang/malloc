/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunk_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 21:16:35 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/09 21:18:14 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

enum e_chunk_type	get_chunk_type(size_t size)
{
	if (size == 0)
		return (0);
	else if (size <= TINY)
		return (TINY);
	else if (size <= SMALL)
		return (SMALL);
	else
		return (LARGE);
}
