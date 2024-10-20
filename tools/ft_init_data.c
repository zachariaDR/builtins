#include "builtins.h"

void    ft_init_data(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    g_env = ft_fill_env(env);
    
}
