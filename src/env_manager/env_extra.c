#include "../../include/minishell.h"

void    ft_list_del_first(t_env_var **begin_list, void (*free_fct)(void *))
{
    t_env_var *first;
    first = *begin_list;
    if (!first)
        return ;
    if (first->value != NULL)
        free_fct(first->key);
    first->key = NULL;
    if (first->value != NULL)
        free_fct(first->value);
    first->value = NULL;
    *begin_list = first->next;
    first->next = NULL;
    free_fct(first);
}

void    ft_list_del_last(t_env_var **begin_list, void (*free_fct)(void *))
{
    t_env_var *last;

    last = ft_list_last(*begin_list);
    if (!last)
        return ;
    t_env_var *tmp;
    tmp = *begin_list;
    if (tmp == last)
    {
        if (tmp->key)
            free_fct(tmp->key);
        tmp->key = NULL;
        if (tmp->value)
            free_fct(tmp->value);
        tmp->value = NULL;
        free_fct(last);
        begin_list = NULL;
        return ;
    }
    while (tmp->next->next)
        tmp = tmp->next;
    if (last->key)
        free_fct(last->key);
    last->key = NULL;
    if (last->key)
        free_fct(last->value);
    last->value = NULL;
    tmp->next = NULL;
    free_fct(last);
    last = NULL;
}

void    ft_list_del(t_env_var **begin_list, void *data, void (*free_fct)(void *))
{
    t_env_var *tmp;
    t_env_var *tmp2;
    
    tmp = *begin_list;
    tmp2 = *begin_list;
    if (!strcmp(tmp->key, data))
    {
        ft_list_del_first(begin_list, free);
        return ;
    }
    if (!strcmp(ft_list_last(*begin_list)->key, data))
    {
        ft_list_del_last(begin_list, free);
        return ;
    }
    while (tmp)
    {
        if (!strcmp(tmp->key, data))
            break;
        tmp =  tmp->next;
    }
    if (!tmp)
        return ;
    while (tmp2)
    {
        if (!strcmp(tmp2->next->key, data))
            break;
        tmp2 =  tmp2->next;
    }
    if (!tmp2)
        return ;
    tmp2->next = tmp->next;
    if (tmp->key)
        free_fct(tmp->key);
    tmp->key = NULL;
    if (tmp->value)
        free_fct(tmp->value);
    tmp->next = NULL;
    free_fct(tmp);
}
