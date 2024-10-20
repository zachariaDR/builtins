#include "ft_a_list.h"

void    ft_list_del_nth(t_env **begin_list, void *data, void (*free_fct)(void *))
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
    tmp->name = NULL;
    tmp->next = NULL;
    free_fct(tmp);
}
