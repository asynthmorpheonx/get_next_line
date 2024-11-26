#include "get_next_line_bonus.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);

int main(void)
{
    int fd1 = open("test1.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);
    int fd3 = open("test3.txt", O_RDONLY);
    char *line1, *line2, *line3;
    int keep_reading = 1;

    // Read lines from all three tests concurrently
    while (keep_reading)
    {
        keep_reading = 0;
        line1 = get_next_line(fd1);
        if (line1)
        {
            printf("test 1: %s", line1);
            free(line1);
            keep_reading = 1;
        }

        line2 = get_next_line(fd2);
        if (line2)
        {
            printf("test 2: %s", line2);
            free(line2);
            keep_reading = 1;
        }

        line3 = get_next_line(fd3);
        if (line3)
        {
            printf("test 3: %s", line3);
            free(line3);
            keep_reading = 1;
        }
    }
    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}
