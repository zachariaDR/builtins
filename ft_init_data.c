#include "builtins.h"

void    ft_init_data(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    // ft_init_bi(); i will use it to init every function for builtins
    g_env = ft_fill_env(env);
    
}
