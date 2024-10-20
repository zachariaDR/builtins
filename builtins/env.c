#include "../builtins.h"

void    ft_env(char **arg)
{
    (void)arg;
    ft_print_list(&g_env);
}
