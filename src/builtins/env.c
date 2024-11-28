#include "../../include/builtins.h"

void    ft_env(t_env_var *env_vars)
{
    int i;
    t_env_var *llist;

    i = 0;
    if (!env_vars)
        return ;
    llist = env_vars;
    while (llist)
    {
        if (llist->value)
        {
            printf("%s", (char *)(llist)->key);
            printf("=%s\n", (char *)(llist)->value);
            i++;
        }
        llist = (llist)->next;
    }
}
