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
		printf("\033[1;35mgnl = %s\033[0m\n", line);
		free(line);
	} while (line);

	close (fd);
    return (0);
}