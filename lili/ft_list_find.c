#include "ft_a_list.h"

t_env *ft_list_find(t_env *begin_list, void *data_ref, char x, int (*cmp)())
{
    t_env   *tmp;
    char    *target;

    tmp = begin_list;
    int i = 0;
    if (!data_ref)
        return (NULL);
    while (tmp)
    {
        // printf("index %d -----> %s\n", i, (char *)tmp->name);
        if (x == 'n')
            target = tmp->name;
        else if (x == 'v')
            target = tmp->value;
        if ((*((int (*)(void *, void *))cmp))(target, data_ref) == 0)
        {
            printf("index %d -----> %s\n", i, (char *)target);
            return (tmp);
        }
        i++;
        tmp = tmp->next;
    }
    return (NULL);
}
