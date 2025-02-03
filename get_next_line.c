#include "get_next_line.h"

t_list *find_last_node(t_list *list)
{
    if (list == NULL)
        return (NULL);
     while (list -> next)
     {
        list = list ->next;
     }
       
}

void append_line_to_list(t_list **list, char *buff)
{
    t_list *new_node;
    t_list *last_node;

    last_node = find_last_node(*list);
    new_node = malloc(sizeof(t_list));
        if (new_node == NULL)
            return NULL;
    if (last_node == NULL)  
        *list = new_node;
    else
        last_node ->next = new_node;
    new_node -> str_buff = buff;
    new_node ->next = NULL;
    
}

int found_new_line(t_list *list)
{
    int i;
    if (list == NULL)
        return (NULL);
    i = 0;
    while (list)
    {
        while (list -> str_buff[i] && BUFF_SIZE > i)
        {
            if (list -> str_buff[i] == '\n')
                return 1;
            i++;
        }
        list = list -> next;
    }
    return (0);
}



void *find_line(int fd, t_list **list)
{
    int chars_read;
    char *buff;

    while (!found_new_line(*list))
    {
        buff = malloc(BUFF_SIZE + 1);
        if(!buff)
            return (NULL);
        chars_read = read(fd, buff, BUFF_SIZE);
        if (!chars_read)
        {
            free(buff);
            return (NULL);
        }
        append_line_to_list(list, buff);    
    }
    
}

char *get_line(t_list *list)
{
    int str_len;
    char *line;
    int i;
    if (list == NULL)
        return (NULL);
    str_len = get_len_until_new_line(list);
    line = malloc(str_len + 1);
    if (line == NULL)
        return (NULL);

    i = 0;
    cpy_line_to_list(list, line);
    
}

void cpy_line_to_list(t_list *list, char *line)
{
    int i;
    int j;

    j = 0;
    while (list)
    {
        i = 0;
        while (list -> str_buff[i])
        {
            if (list -> str_buff[i] == '\n')
                line[j++] = '\n';
                line[j] = '\0';

            line[j] == list -> str_buff[i] ; 
        }
        list = list -> next;
    }
}

int get_len_until_new_line(t_list *list)
{
    int counter;
    int i;

    counter = 0;
    if (list == NULL)
        return(NULL);
    
    while (list) 
    {   
        i = 0;
        while(list -> str_buff[i])
        {
            if (list -> str_buff[i] == '\n')
                counter++;
                return(counter);
            i++;
            counter++;
        }
        list = list -> next;   
    }
    return (counter);
}

char get_next_line(int fd)
{
    static t_list *list = NULL;
    char *next_line;

    if (fd < 0 || BUFF_SIZE <= 0)
        return NULL;
    find_line(fd, &list);
    if (list == NULL)
        return (NULL);
    next_line= get_line(list);
}