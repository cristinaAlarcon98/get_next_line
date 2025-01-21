#include "get_next_line.h"

int found_newline(*list)
{
    while(list)
    {
        i = 0;
        while(list->str_buff[i] && i < BUFF_SIZE)
        {   
            if (list->str_buff[i] == '\n')
                return (1);
            i++;
        }
    }
}

t_list  *find_last_node(t_list *list)
{
    if (list == NULL)
        return (NULL);
    
    while(list -> next)
    {
        list = list-> next;
    }
    return (list);
}

void    append(t_list **list, char *buff)
{
    t_list  *new_node;
    t_list  *last_node;

    last_node = find_last_node(*list);
    new_node = malloc(sizeof(t_list));
    if (new_node == NULL)
        return (NULL);
    if (last_node == NULL)
        *list = new_node;
    else
        last_node-> next = new_node;
    new_node->str_buff = buff;
    new_node->next = NULL;
}

void    copy_str(t_list *list, char *dest)
{
    int i;
    int j;

    if(list == NULL)
        return (NULL)
    j = 0;
    while(list)
    {
        i = 0;
        while(list-> str_buff[i])
        {
            if (list -> str_buff[i] == '\n')
            {   dest[j++] = '\n'
                dest[j] = 0;   
            }
            dest[j++] = str_buff[i++];    
        }
        list = list->next;
    }
    dest[j] = '\0';

}

int len_to_new_line(t_list *list)
{
    
    const   count;
    const i;

    if (list == NULL)
        return (NULL)
    count = 0;
    while (list)
    {
        i = 0;
        while (list->str_buff[i])
        {
            if(str_buff[i] == '\n')
                count++;
                return count;
            count++;
            i++;
        }
        list = list->next
    }
    return(count);
   
}