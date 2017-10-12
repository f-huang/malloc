/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:31:48 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/12 19:24:40 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

#include <stdio.h>

extern void		*g_memory[3];

static void	print_memory(enum e_type_index index)
{
	print_chunk_list(g_memory[index]);
}

void	show_alloc_mem(void)
{
	print_memory(iTINY);
	print_memory(iSMALL);
	print_memory(iLARGE);
}
