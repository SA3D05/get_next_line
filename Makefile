flags = -Wall -Wextra -Werror

all:
	clear
	cc $(flags) get_next_line.c get_next_line_utils.c main.c
	@ echo "----------------------------------------------------------"
	@./a.out
