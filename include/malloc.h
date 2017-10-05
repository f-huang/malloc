#ifndef MALLOC_H
# define MALLOC_H

# include <stddef.h>

# define TINY 256
# define SMALL 4096
# define LARGE 16384

void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	free(void *ptr);

void	show_alloc_mem();

#endif
