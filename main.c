/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:52:10 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/19 11:37:21 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
// #include <stdlib.h>
#include <stdio.h>
// #include <string.h>

static void	test_malloc_and_free(void)
{
	// printf("--------------------------___MALLOC___FREE___\n");
	// void *ptr0 = NULL;
	void *ptr1 = NULL;
	// void *ptr2 = NULL;
	// void *ptr3 = NULL;
	// void *ptr4 = NULL;
	// void *ptr5 = NULL;
	ptr1 = realloc(ptr1, 20);
	printf("%p\n", ptr1);
	// ptr0 = malloc(0);
	// ptr1 = malloc(128);
	// ptr2 = malloc(1024);
	// ptr3 = malloc(2);
	// ptr4 = malloc(2000);
	// ptr5 = malloc(4000);
	//
	// show_alloc_mem();
	// printf("----------\n");
	// // printf("[0] %p\n[1] %p\n[2] %p\n[3] %p\n[4] %p\n[5] %p\n\n", ptr0, ptr1, ptr2, ptr3, ptr4, ptr5);
	//
	// free(ptr0);
	// free(ptr1);
	// free(ptr2);
	// free(ptr3);
	// free(ptr5);
	// free(ptr4);
	show_alloc_mem();
	// printf("[0] %p\n[1] %p\n[2] %p\n[3] %p\n[4] %p\n[5] %p\n\n", ptr0, ptr1, ptr2, ptr3, ptr4, ptr5);
}

static void	test_realloc(void)
{
	printf("--------------------------___REALLOC___\n");
	void *ptr0 = NULL;
	void *ptr1 = NULL;
	void *ptr2 = NULL;
	void *ptr3 = NULL;
	void *ptr4 = NULL;
	void *ptr5 = NULL;
	void *ptr6 = NULL;

	ptr0 = malloc(0);
	ptr1 = malloc(128);
	ptr2 = malloc(128);
	ptr3 = malloc(128);
	ptr4 = malloc(1024);
	// ptr5 = malloc(1025);
	show_alloc_mem();
	// printf("[0] %p\n[1] %p\n[2] %p\n[3] %p\n[4] %p\n[5] %p\n", ptr0, ptr1, ptr2, ptr3, ptr4, ptr5);

	ptr0 = realloc(ptr0, 10);
	ptr1 = realloc(ptr1, 128);
	ptr2 = realloc(ptr2, 120);
	ptr3 = realloc(ptr3, 0);
	ptr4 = realloc(ptr4, 1025);
	// ptr5 = realloc(ptr5, 100);
	// ptr6 = realloc(ptr5, 2000);
	show_alloc_mem();
	// printf("[0] %p\n[1] %p\n[2] %p\n[3] %p\n[4] %p\n[5] %p\n[6] %-20p\n", ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6);
	free(ptr6);
	show_alloc_mem();
}

int		main(void)
{
	test_malloc_and_free();
	// test_realloc();
	// malloc(1024);
	// malloc(1024 * 32);
	// malloc(1024 * 1024);
	// malloc(1024 * 1024 * 16);
	// malloc(1024 * 1024 * 128);
	// show_alloc_mem();

	return (0);
}
