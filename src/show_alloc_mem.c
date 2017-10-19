/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:31:48 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/19 18:37:13 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "malloc.h"

extern void		*g_memory[3];

static void	print_long_base(long n, int base)
{
	static char		ret[24];
	const char		pattern[17] = "0123456789ABCDEF";
	unsigned long	uin;
	int				len;

	ft_bzero(ret, 24);
	uin = (unsigned long)n;
	len = ft_nbrlen_base(uin, base);
	while (--len >= 0)
	{
		ret[len] = (pattern[uin % base]);
		uin /= base;
	}
	ft_putstr(ret);
}

static void	print_pointer(void *ptr)
{
	ft_putstr("0x");
	print_long_base((long)ptr, 16);
}

static void	print_octets_string(size_t size)
{
	ft_putstr(" octet");
	if (size > 1)
		ft_putstr("s");
	ft_putchar('\n');
}

static void	print_memory(enum e_chunk_type type, unsigned long *total)
{
	int				index;
	t_chunk			*iterator;

	index = get_type_index(type);
	iterator = g_memory[index];
	ft_putstr(get_type_name(type));
	ft_putstr(" : ");
	print_pointer(iterator);
	ft_putchar('\n');
	while (iterator)
	{
		if (iterator->is_used)
		{
			print_pointer(iterator + 1);
			ft_putstr(" - ");
			print_pointer((unsigned char*)\
				iterator + sizeof(t_chunk) + iterator->size);
			ft_putstr(" : ");
			print_long_base(iterator->size, 10);
			print_octets_string(iterator->size);
			*total += iterator->size;
		}
		iterator = iterator->next;
	}
}

void		show_alloc_mem(void)
{
	unsigned long	total;

	total = 0;
	print_memory(TINY, &total);
	print_memory(SMALL, &total);
	print_memory(LARGE, &total);
	ft_putstr("Total : ");
	print_long_base(total, 10);
	print_octets_string(total);
}
