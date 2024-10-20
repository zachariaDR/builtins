#include "ft_a_list.h"


void    ft_print_list(t_env **list)
{
    printf("\n\n\ni get here lol! \n");
    int i;
    t_env *llist;

    i = 0;
    if (list_is_empty(list))
    {
        printf("list is empty!\n");
        return ;
    }
    llist = *list;
    while (llist)
    {
        printf("node %d --> %s\n", i, (char *)(llist)->name);
        // printf("%s\n", (char *)(llist)->value);

        // printf("%s = %s\n", (char *)list->data, (char *)list->next);
        llist = (llist)->next;
        i++;
    }
    // list = (list)->next;

    printf("node %d --> %s\n", i, (char *)(llist));
    printf("------------\n\n");
}
