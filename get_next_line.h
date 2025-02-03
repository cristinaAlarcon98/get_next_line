#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFF_SIZE
#define BUFF_SIZE 15
#endif


typedef struct s_list
{
    char *str_buff;
    struct s_list *next;
}   t_list;
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>

#endif