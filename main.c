#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

   do
	{
		line =  get_next_line(fd);
		printf(" gnl = %s\n", line);
		free(line);
	} while (line);

    return (0);
}