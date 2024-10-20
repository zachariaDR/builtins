#include "ft_a_list.h"

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
        tmp->name = NULL;
        tmp->value = NULL;
        free_fct(last);
        begin_list = NULL;
        return ;
    }
    while (tmp->next->next)
        tmp = tmp->next;

    last->name = NULL;
    last->value = NULL;
    tmp->next = NULL;
    free_fct(last);
    last = NULL;
}
