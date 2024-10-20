#include "ft_a_list.h"

void ft_sorted_list_insert(t_env **begin_list, char *name, char *value, int (*cmp)())
{
    t_env *n_new;
    t_env *tmp;

    ft_list_sort(begin_list, cmp);
    n_new = ft_create_elem(name, value);
    tmp = *begin_list;
    while (tmp)
    {
        if ((*(int (*)(char *, char *))cmp)(name, tmp->name) < 0)
            break;
        tmp = tmp->next;
    }
    if (!tmp)
    {
        ft_list_push_back(begin_list, name, value);
        return ;
    }
    printf("we got %s here\n", (char *)tmp->name);
    ft_list_push_pre_nth(begin_list, name, tmp->name, tmp->value);
}