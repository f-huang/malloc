#ifndef MALLOC_H
# define MALLOC_H

# include <stddef.h>

# define STRINGIFY(x) #x
# define TOSTRING(x) STRINGIFY(x)
// # define TINY 256
// # define SMALL 4096
// # define LARGE 16384

enum e_chunk_type
{
	TINY = 128,
	SMALL = 1024,
	LARGE = 4096
};

typedef struct	s_chunk
{
	// void			*ptr;
	int					is_used;
	enum e_chunk_type	type;
	size_t				size;
	struct s_chunk		*next;
}				t_chunk;

typedef struct	s_memory
{
	t_chunk			*list_head;
	t_chunk			*list_tail;
	size_t			space_left;
}				t_memory;

t_memory			g_memory;

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
void				chunk_add(void *ptr, size_t size, enum e_chunk_type type);
void				chunk_remove(t_chunk *to_remove, int should_unmap);
void				*chunk_split(size_t size);

/*
**		MEMORY
*/
void				*allocate_memory(size_t size);
enum e_chunk_type	get_chunk_type(size_t size);
const char			*get_type_name(enum e_chunk_type type);
size_t				get_size_to_allocate(size_t size);

#endif
