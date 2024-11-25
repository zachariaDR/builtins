#include "ft_a_list.h"

void    ft_list_del_first(t_env **begin_list, void (*free_fct)(void *))
{
    t_env *first;
    first = *begin_list;
    if (!first)
        return ;
    if (first->value != NULL)
        free_fct(first->name);
    first->name = NULL;
    if (first->value != NULL)
        free_fct(first->value);
    first->value = NULL;
    *begin_list = first->next;
    first->next = NULL;
    free_fct(first);
}

void    ft_list_del_last(t_env **begin_list, void (*free_fct)(void *))
{
    t_env *last;

    last = ft_list_last(*begin_list);
    if (!last)
        return ;
    t_env *tmp;
    tmp = *begin_list;
    if (tmp == last)
    {
        if (tmp->name)
            free_fct(tmp->name);
        tmp->name = NULL;
        if (tmp->value)
            free_fct(tmp->value);
        tmp->value = NULL;
        free_fct(last);
        begin_list = NULL;
        return ;
    }
    while (tmp->next->next)
        tmp = tmp->next;
    if (last->name)
        free_fct(last->name);
    last->name = NULL;
    if (last->name)
        free_fct(last->value);
    last->value = NULL;
    tmp->next = NULL;
    free_fct(last);
    last = NULL;
}

void    ft_list_del(t_env **begin_list, void *data, void (*free_fct)(void *))
{
    t_env *tmp;
    t_env *tmp2;
    
    tmp = *begin_list;
    tmp2 = *begin_list;
    if (!strcmp(tmp->name, data))
    {
        ft_list_del_first(begin_list, free);
        return ;
    }
    if (!strcmp(ft_list_last(*begin_list)->name, data))
    {
        ft_list_del_last(begin_list, free);
        return ;
    }
    while (tmp)
    {
        if (!strcmp(tmp->name, data))
            break;
        tmp =  tmp->next;
    }
    if (!tmp)
        return ;
    while (tmp2)
    {
        if (!strcmp(tmp2->next->name, data))
            break;
        tmp2 =  tmp2->next;
    }
    if (!tmp2)
        return ;
    tmp2->next = tmp->next;
    if (tmp->name)
        free_fct(tmp->name);
    tmp->name = NULL;
    if (tmp->value)
        free_fct(tmp->value);
    tmp->next = NULL;
    free_fct(tmp);
}
