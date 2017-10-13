# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 15:45:39 by fhuang            #+#    #+#              #
#    Updated: 2017/10/13 14:48:20 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Editable =====

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME		:=	libft_malloc_$(HOSTTYPE).so
MALLOCLIB	:=	libft_malloc.so
# ====================

# ===== Standard =====
CC		:=	clang -pipe
CFLAGS	:=	-Wall -Wextra -Werror -g3
SOFLAGS	:=	-shared
SRCDIR	:=	src/
OBJDIR	:=	obj/
BINDIR	:=	bin/
INCDIR	:=	include/
LIBFT	:=	libft/
LIBDIR	:=	$(LIBFT)lib/
SRC		:=	$(SRCDIR)allocate_memory.c			\
			$(SRCDIR)chunk_remove.c				\
			$(SRCDIR)chunk_add.c				\
			$(SRCDIR)find_chunk.c				\
			$(SRCDIR)free.c						\
			$(SRCDIR)get_chunk_type.c			\
			$(SRCDIR)get_last_chunk.c			\
			$(SRCDIR)get_size_to_allocate.c		\
			$(SRCDIR)get_type_index.c			\
			$(SRCDIR)get_type_name.c			\
			$(SRCDIR)get_unused_chunk.c			\
			$(SRCDIR)malloc.c					\
			$(SRCDIR)realloc.c					\
			$(SRCDIR)show_alloc_mem.c
OBJ		:=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
INC		:=	-I./$(INCDIR) -I./$(LIBFT)$(INCDIR)
LIB		:=	-lpthread -L./$(LIBDIR) -lft -lftprintf
CACHEF	:=	.cache_exists
# ====================

# ====== Colors ======
CLEAR		= "\033[2K"
UP			= "\033[A"
EOC			= "\033[0;0m"
BLACK		= "\033[0;30m"
RED			= "\033[0;31m"
GREEN		= "\033[0;32m"
YELLOW		= "\033[0;33m"
BLUE		= "\033[0;34m"
PURPLE		= "\033[0;35m"
CYAN		= "\033[0;36m"
WHITE		= "\033[0;37m"
# ====================

.PHONY: all libft norme clean fclean re link_malloc
.SILENT:

all: libft $(NAME) link_malloc

$(NAME): $(OBJ)
	$(CC) $(SOFLAGS) $(CFLAGS) $(OBJ) -o $@ $(LIB) $(INC)
	echo $(GREEN)" $@ compiled !"$(EOC)

$(OBJDIR)%.o: $(SRCDIR)%.c $(CACHEF)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	printf $(GREEN)"|"$(EOC)

$(CACHEF):
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	test -d $(CACHEF) || touch $(CACHEF)

%.c:
	printf $(RED)"Missing file : $@\n"$(EOC)

libft:
	make -C $(LIBFT)

link_malloc:
	rm -f $(MALLOCLIB)
	ln -s $(NAME) $(MALLOCLIB)

norme:
	norminette $(SRCDIR) $(INCDIR) | grep -v Norme -B1 || true
	norminette $(LIBFT)$(SRCDIR) $(LIBFT)$(INCDIR) | grep -v Norme -B1 || true

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJDIR) $(CACHEF) $(RESULTF)
	printf $(YELLOW)"All objects removed\n"$(EOC)

fclean: clean
	rm -f $(NAME) $(MALLOCLIB)
	printf $(RED)"$(NAME) removed\n"$(EOC)

re: fclean all
