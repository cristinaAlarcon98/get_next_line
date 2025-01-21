
#include "get_next_line.h"
#include <stdio.h>


void get_next_line(int fd)
{
    char *read_data;

    read_data = malloc(BUFF_SIZE);
    // if(!buff)
    //     return (NULL);
    
    read(fd, read_data, BUFF_SIZE );

    write(1, read_data, BUFF_SIZE);
}

int main(int argc, char const *argv[])
{
    int fd;

    fd = open("text.txt", O_RDONLY);
    get_next_line(fd);
}
