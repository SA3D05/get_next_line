


#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"



int main(void)
{
    int fd;
    int i;
    char *str;

    fd = open("file.txt", O_RDONLY);
    i = 1;
    str = get_next_line(fd);
    printf("%d: %s",i++ , str);
    free(str);
    str = get_next_line(fd);
    printf("%d: %s",i++ , str);
    free(str);
    str = get_next_line(fd);
    printf("%d: %s",i++ , str);
    free(str);
    return 0;
}
