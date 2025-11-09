

CFLAGS = -Wall -Wextra -Werror

all: get_next_line_utils.c get_next_line.c main.c get_next_line.h
	cc get_next_line_utils.c get_next_line.c main.c

test: all run valgrind
	

valgrind:
	valgrind ./a.out 

run:
	./a.out