#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    //int fd = open( "/home/elodie/Get_next_line/txt",O_RDONLY);
    int fd = 0;
    char    *line;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        printf("%s", line);
        free (line);
    }
    return (0);
}