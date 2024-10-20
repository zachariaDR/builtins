#include "ft_a_list.h"

void    ft_list_set_value(t_env *begin_list, char *name, char *n_value, int (*cmp)())
{
    t_env   *node;

    node = ft_list_find(begin_list, name, 'n', cmp);
    node->value = n_value;
}