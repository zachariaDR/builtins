#include "builtins.h"

t_env *g_env;

int main(int ac, char **av, char **env)
{
    ft_init_data(ac, av, env);

    // ft_export(av);
    ft_env(av);
    // ft_print_list(&g_env);

    return (0);
}
