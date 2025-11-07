

#include "get_next_line.h"
#include <fcntl.h>

// void readd(int fd)
// {
//     char buf[11];
//     read(fd, buf, 5);
//     buf[5] = '\0';
//     printf("%s\n", buf);
// }
int main()
{
    int fd = open("file.txt", O_RDONLY);
    int i = 1;
    char *str = get_next_line(fd);
    printf("%d: %s", i++, str);

    str = get_next_line(fd);
    printf("%d: %s", i++, str);

    str = get_next_line(fd);
    printf("%d: %s", i++, str);

    return 0;
}