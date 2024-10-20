#include "ft_a_list.h"


void    ft_print_list(t_env **list)
{
    int i;
    t_env *llist;

    i = 0;
    if (list_is_empty(list))
        return ;
    llist = *list;
    while (llist)
    {
        printf("node %d --> %s\n", i, (char *)(llist)->name);
        llist = (llist)->next;
        i++;
    }

    printf("node %d --> %s\n", i, (char *)(llist));
    printf("------------\n\n");
}
