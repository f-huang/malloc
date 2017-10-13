#!/bin/sh
filename="test"
clang -o $filename main.c -L. -lft_malloc -Iinclude
./$filename
