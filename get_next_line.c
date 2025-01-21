
#include "get_next_line.h"
#include <stdio.h>



void *get_line(t_list *list)
{
    int str_len;
    char    *next_str;

    if(list == NULL)
        return (NULL);

    str_len = len_to_newline(list);
    next_str = malloc(str_len + 1);
    if(!next_str)
        return (NULL)

    copy_str(list, next_str);
    return (next_str);
}



void create_list(t_list **list, int fd)
{
    int char_read;
    char *buff;

    while(!found_newline(*list))
    {
        buff = malloc(BUFF_SIZE + 1);
        if (!buff)
            return NULL;

        char_read = read(fd, buff, BUFF_SIZE);
        if(!char_read)
        {
            free(buff);
            return NULL;
        }
        buff[char_read] = '\0';
        append(list, buff);
    }
}
char  *get_next_line(int fd)
{
    char *next_line;
    static t_list  *list=NULL;

    if (fd < 0 || BUFF_SIZE <= 0 || read(fd, next_line, BUFF_SIZE) < 0)
        return (NULL);


    create_list(&list, fd);

    if (list == NULL)
        return(NULL);

    next_line = get_line(list);

    polish_list(&list);
    return(next_line);
}

int main(int argc, char const *argv[])
{
    int fd;

    fd = open("text.txt", O_RDONLY);
    get_next_line(fd);
}
