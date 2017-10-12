/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:25:31 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/12 13:27:16 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

enum e_type_index	get_type_index(enum e_chunk_type type)
{
	if (type == TINY)
		return (iTINY);
	else if (type == SMALL)
		return (iSMALL);
	else
		return (iLARGE);
}
