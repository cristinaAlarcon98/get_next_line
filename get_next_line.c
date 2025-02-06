/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cralarco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:30:14 by cralarco          #+#    #+#             */
/*   Updated: 2025/01/20 20:10:20 by cralarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void find_line(int fd, t_list **list)
{
    int chars_read;
    char *buff;

    while (!found_new_line(*list))
    {
        buff = malloc(BUFF_SIZE + 1);
        if (!buff)
            return ;
        chars_read = read(fd, buff, BUFF_SIZE);
        if (!chars_read)
        {
            free(buff);
            return ;
        }
        append_line_to_list(list, buff);
    }
}

char *get_line(t_list *list)
{
    int str_len;
    char *line;
    if (list == NULL)
        return (NULL);
    str_len = get_len_until_new_line(list);
    line = malloc(str_len + 1);
    if (line == NULL)
        return (NULL);

    cpy_list_to_line(list, line);
    return (line);
}




void polish_list(t_list **list)
{
    t_list *last_node;
    t_list *clean_node;
    char *buf;
    int i;
    int j;

    buf = malloc(BUFF_SIZE + 1);
    clean_node = malloc(sizeof(t_list));
    if (buf == NULL || clean_node == NULL)
        return ;
    last_node = find_last_node(*list);
    i = 0;
    j = 0;
    while (last_node -> str_buff[i] && last_node -> str_buff[i] != '\n')
        i++;
    while (last_node -> str_buff[i] && last_node -> str_buff[++i])
        buf[j++] = last_node -> str_buff[i];
    buf[j] = '\0';
    clean_node -> str_buff = buf;
    clean_node -> next = NULL;
    dealloc(list, clean_node, buf);    
}

char *get_next_line(int fd)
{
    static t_list *list = NULL;
    char *next_line;

    if (fd < 0 || BUFF_SIZE <= 0)
        return (NULL);
    find_line(fd, &list);
    if (list == NULL)
        return (NULL);
    next_line = get_line(list);
    polish_list(&list);
    return (next_line);
}

// #include <fcntl.h>  
// #include <stdio.h>

// int main()
// {
//     int fd;
//     char *line;

//     fd = open("text.txt", O_RDONLY);
//     line = get_next_line(fd);
//     printf("%s", line);
//     free(line);

//     // line = get_next_line(fd);
//     // printf("%s", line);
//     // free(line);

//     // line = get_next_line(fd);
//     // printf("%s", line);
//     // free(line);

//     // line = get_next_line(fd);
//     // printf("%s", line);
//     // free(line);

//     //close(fd); // Close the file descriptor after reading
//     return (0);
// }