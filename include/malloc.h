/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 12:10:57 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/20 10:10:28 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stddef.h>
# include <pthread.h>

# define STRINGIFY(x) #x
# define TOSTRING(x) STRINGIFY(x)

# define NUMBER_OF_LINKS 100

enum				e_chunk_type
{
	TINY = 128,
	SMALL = 1024,
	LARGE = 4096
};

enum				e_type_index
{
	iTINY = 0,
	iSMALL = 1,
	iLARGE = 2
};

typedef struct		s_chunk
{
	int					is_used;
	size_t				size;
	enum e_chunk_type	type;
	struct s_chunk		*next;
}					t_chunk;

void				*g_memory[3];
pthread_mutex_t		g_mutex;

/*
**		SUBJECT'S FUNCTIONS
*/
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				free(void *ptr);

void				show_alloc_mem();

/*
**		CHUNK
*/
void				chunk_add(void *ptr, size_t size);
void				chunk_remove(t_chunk **list, t_chunk *needle);

t_chunk				*find_chunk_in_memory_stack(t_chunk *list, void *ptr);
t_chunk				*find_chunk(void *ptr);

enum e_chunk_type	get_chunk_type(size_t size);
t_chunk				*get_last_chunk(t_chunk *list);
enum e_type_index	get_type_index(enum e_chunk_type type);
t_chunk				*get_unused_chunk(enum e_chunk_type type, size_t size);

void				print_chunk_list(t_chunk *list);

/*
**		MEMORY
*/
void				*allocate_memory(size_t size);
size_t				get_size_to_allocate(size_t size);
const char			*get_type_name(enum e_chunk_type type);

#endif
