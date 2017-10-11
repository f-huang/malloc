/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:52:10 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/10 21:41:20 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
// #include <stdlib.h>
int		main(void)
{
	void *ptr0;
	void *ptr1;
	void *ptr2;
	void *ptr3;
	void *ptr4;

	// ptr0 = malloc(0);
	ptr1 = malloc(1);
	ptr2 = malloc(2);
	// ptr3 = malloc(1024);
	// ptr4 = malloc(1025);
	show_alloc_mem();
	while (1);
	return (0);
}
