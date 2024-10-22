#include "../builtins.h"

void    ft_env(char **arg)
{
    (void)arg;
    // ft_print_list(&g_env);

    int i;
    t_env *llist;

    i = 0;
    if (list_is_empty(&g_env))
        return ;
    llist = g_env;
    while (llist)
    {
        if (llist->value[0] == '=')
        {
            printf("node %d --> %s", i, (char *)(llist)->name);
            printf("%s\n", (char *)(llist)->value);
            i++;
        }
        llist = (llist)->next;
    }
    printf("node %d --> %s\n", i, (char *)(llist));
    printf("------------\n\n");
}
