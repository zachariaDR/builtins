#include "builtins.h"

t_env *g_env;

int main(int ac, char **av, char **env)
{
    ft_init_data(ac, av, env);
    // ft_print_list(&g_env);
    ft_env(NULL);

    ft_unset("SHLVL");
    ft_env(NULL);

    return (0);
}
