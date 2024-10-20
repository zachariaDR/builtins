#include "ft_a_list.h"

void    ft_list_del_first(t_env **begin_list, void (*free_fct)(void *))
{
    t_env *first;
    first = *begin_list;
    if (!first)
        return ;
    first->value = NULL;
    first->name = NULL;
    *begin_list = first->next;
    first->next = NULL;
    free_fct(first);
}
