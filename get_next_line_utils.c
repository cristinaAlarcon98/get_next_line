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

t_list *find_last_node(t_list *list)
{
    if (list == NULL)
        return (NULL);
    while (list->next)
    {
        list = list->next;
    }
    return (list);
}


void	dealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buff);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->str_buff[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
int get_len_until_new_line(t_list *list)
{
    int counter;
    int i;

    if (list == NULL)
        return (0);
    counter = 0;
    while (list)
    {
        i = 0;
        while (list->str_buff[i])
        {
            if (list->str_buff[i] == '\n')
            {
                counter++;
                return (counter);
            }
            i++;
            counter++;
        }
        list = list->next;
    }
    return (counter);
}

void cpy_list_to_line(t_list *list, char *line)
{
    int i;
    int j;

    j = 0;
    while (list)
    {
        i = 0;
        while (list->str_buff[i])
        {
            if (list->str_buff[i] == '\n')
            {
                line[j++] = '\n';
                line[j] = '\0';
                return ;
            }  
            line[j++] = list->str_buff[i++];
        }
        list = list->next;
    }
    line[j] = '\0';
}

void append_line_to_list(t_list **list, char *buff)
{
    t_list *new_node;
    t_list *last_node;

    last_node = find_last_node(*list);
    new_node = malloc(sizeof(t_list));
    if (new_node == NULL)
        return ;
    if (last_node == NULL)
        *list = new_node;
    else
        last_node->next = new_node;
    new_node->str_buff = buff;
    new_node->next = NULL;
}

int found_new_line(t_list *list)
{
    int i;
    if (list == NULL)
        return (0);
    
    while (list)
    {
        i = 0;
        while (list->str_buff[i] && BUFF_SIZE > i)
        {
            if (list->str_buff[i] == '\n')
                return (1);
            i++;
        }
        list = list->next;
    }
    return (0);
}
