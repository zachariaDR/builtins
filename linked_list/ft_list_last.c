#include "ft_a_list.h"

t_env *ft_list_last(t_env *begin_list)
{
    if (!begin_list)
        return (NULL);
    
    while(begin_list->next)
        begin_list = begin_list->next;
    return (begin_list);
}