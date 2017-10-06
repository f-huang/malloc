#!/bin/sh
filename="test"
clang -o $filename libft_malloc_x86_64_Darwin.so main.c -Iinclude
./$filename
