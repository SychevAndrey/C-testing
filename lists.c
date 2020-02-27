#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

t_list  *create_list(int data)
{
    t_list *list;
    
    list = malloc(sizeof(t_list));
    if (list != NULL)
    {
        list->next = NULL;
        list->data = data;
    }
    return (list);
}

void    push_front(t_list **begin, int data)
{
    t_list *new;

    new = create_list(data);
    new->next = (*begin);
    (*begin) = new;
}

void    print_list(t_list **begin)
{
    t_list *tmp;
    
    tmp = *begin;
    while (tmp)
    {
        printf("%d ", tmp->data);
        
        tmp = tmp->next;
    }
    printf("\n");
}

void delete_if(t_list **head, int data_ref)
{
    t_list  *tmp;
    t_list  *prev;
    
    tmp = *head;
    
    while (tmp->data == data_ref)
    {    
        prev = tmp;
        tmp = tmp->next;
        *head = tmp;
        free(prev);
    }
    while (tmp && head && tmp->next)
    {
        if (tmp->next->data == data_ref)
        {
            prev = tmp->next;
            tmp->next = tmp->next->next;
            free(prev);
            
        }
        tmp = tmp->next;
    }
}

void push_back(t_list *head, int value)
{
    t_list *last;
    t_list *new;
    
    while(head->next)
        head = head->next;
    last = head;
    
    new = malloc(sizeof(t_list));
    new->next = NULL;
    new->data = value;
    last->next = new;
}

int     main(void)
{
    t_list *list;
    t_list **begin;
    int     data;
    
    begin = &list;
    data = 5;
    list = create_list(data);
    push_front(begin, 10);
    push_front(begin, 17);
    push_front(begin, 2);
    push_front(begin, 9);
    push_front(begin, 4);
    push_back(list, 11);
    push_back(list, 13);
    push_front(begin, 6);
    push_front(begin, 6);
    push_front(begin, 6);
    print_list(begin);
    delete_if(begin, 6);
    print_list(begin);
    
    return (0);
}
