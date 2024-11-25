#include "ft_a_list.h"

t_env *ft_list_get(t_env *begin_list, void *data_ref, char x)
{
    t_env   *tmp;
    char    *target;

    tmp = begin_list;
    int i = 0;
    if (!data_ref)
        return (NULL);
    while (tmp)
    {
        if (x == 'n')
            target = tmp->name;
        else if (x == 'v')
            target = tmp->value;
        if (strcmp(target, data_ref) == 0)
        {
            return (tmp);
        }
        i++;
        tmp = tmp->next;
    }
    return (NULL);
}
