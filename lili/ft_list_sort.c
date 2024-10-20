#include "ft_a_list.h"

static void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void    ft_list_sort(t_env **begin_list, int (*cmp)())
{
    t_env *t1;
    t_env *t2;

    if (*begin_list == NULL || !(*begin_list)->next)
        return ;
    t1 = *begin_list;
    t2 = (*begin_list)->next;
    while (t1)
    {
        t2 = t1->next;
        while (t2)
        {
            if ((*((int (*) (void *, void *))cmp))(t1->name, t2->name) > 0)
                ft_swap((&(t1->name)), (&(t2->name)));
            t2 = t2->next;
        }
        t1 = t1->next;
    }
}
