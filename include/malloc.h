#ifndef MALLOC_H
# define MALLOC_H

# include <stddef.h>

// # define TINY 256
// # define SMALL 4096
// # define LARGE 16384

enum e_chunk_size
{
	TINY = 256,
	SMALL = 4096,
	LARGE = 8192
};

typedef struct	s_chunk
{
	void			*ptr;
	size_t			size;
	struct s_chunk	*next;
}				t_chunk;

typedef struct	s_memory
{
	t_chunk		chunk_list;
	size_t		total_space_allocated;
	size_t		space_left;
}				t_memory;

t_memory		g_memory;

void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			free(void *ptr);

void			show_alloc_mem();


size_t			get_size_to_allocate(size_t size);

#endif
