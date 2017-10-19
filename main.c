/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:52:10 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/19 18:00:13 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
// #include <stdlib.h>
#include <stdio.h>
// #include <string.h>
#include <unistd.h>
#include <strings.h>

#define M (1024 * 1024)

void print(char *s)
{
	write(1, s, strlen(s));
}

static void	test_malloc_and_free(void)
{
	// printf("--------------------------___MALLOC___FREE___\n");
	void *ptr0 = NULL;
	void *ptr1 = NULL;
	void *ptr2 = NULL;
	void *ptr3 = NULL;
	void *ptr4 = NULL;
	void *ptr5 = NULL;
	// printf("%p\n", ptr1);
	ptr0 = malloc(0);
	ptr1 = malloc(128);
	ptr1 = realloc(ptr1, 20);
	ptr2 = malloc(1024);
	ptr3 = malloc(2);
	ptr4 = malloc(2000);
	ptr5 = malloc(4000);
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

static void	test()
{
	int		i;
	void	*ptr;

	i = 0;
	while (i < 5000)
	{
		ptr = malloc(25);
		// printf("%p\n", ptr);
		++i;
	}
	show_alloc_mem();
}

static void	test0()
{
	int		i;

	i = 0;
	while (i < 1024)
		++i;
}

static void	test1()
{
	int i;
	char *addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		i++;
	}
	// show_alloc_mem();
}
static void	test3()
{
	char *addr1;
	char *addr3;

	addr1 = (char*)malloc(16*M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr3 = (char*)realloc(addr1, 128*M);
	addr3[127*M] = 42;
	print(addr3);
}

static void	test4()
{
	char	*addr;

	addr = malloc(16);
	free(NULL);
	free((void *)addr + 5);
	if (realloc((void *)addr + 5, 10) == NULL)
		print("Bonjours\n");
}

int		main(void)
{
	test4();
	// test_malloc_and_free();
	// test_realloc();
	// malloc(1024);
	// malloc(1024 * 32);
	// malloc(1024 * 1024);
	// malloc(1024 * 1024 * 16);
	// malloc(1024 * 1024 * 128);
	// show_alloc_mem();

	return (0);
}
