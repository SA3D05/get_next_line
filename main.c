#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *str;

	fd = open("files_to_read/input.txt", O_RDONLY);

	for (int i = 1; i < 5; i++)
	{
		str = get_next_line(fd);
		printf("LINE [%d]: {%s}\n", i, str);
		free(str);
	}
}
