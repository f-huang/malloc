/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:22:15 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/12 13:24:36 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_chunk	*get_last_chunk(t_chunk *list)
{
	t_chunk		*iterator;

	iterator = list;
	while (iterator && iterator->next)
		iterator = iterator->next;
	return (iterator);
}
