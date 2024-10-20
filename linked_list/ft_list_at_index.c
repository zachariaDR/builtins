#include "ft_a_list.h"

t_env   *ft_list_at_index(t_env *begin_list, unsigned int nbr)
{
    t_env *delter;
    int size;

    delter = begin_list;    
    size = 0;
    while (delter && size < nbr)
    {
        delter = delter->next;
        size++;
    }
    if (delter)
        return (delter);
    else
        return (NULL);
}
