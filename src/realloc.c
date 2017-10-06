/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:42:20 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/06 15:59:34 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <stddef.h>

void	*realloc(void *ptr, size_t size)
{
	if (!ptr)
		return (NULL);
	(void)size;
	return (ptr);
}
