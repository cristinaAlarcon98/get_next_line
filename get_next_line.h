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
#include <unistd.h>


void find_line(int fd, t_list **list);
char *get_line(t_list *list);
void polish_list(t_list **list);
int found_new_line(t_list *list);
void append_line_to_list(t_list **list, char *buff);
void cpy_list_to_line(t_list *list, char *line);
int get_len_until_new_line(t_list *list);
void dealloc(t_list **list, t_list *clean_node, char *buf);
t_list *find_last_node(t_list *list);


#endif