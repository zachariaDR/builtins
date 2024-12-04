#include "../../include/minishell.h"

int     is_n_chain_option(char *str)
{
    int i;

    i = 1;
    if (!str || str[0] != '-')
        return (0);
    while (str[i])
    {
        if (str[i] != 'n')
            return (0);
        i++;
    }
    return (1);
}

void    ft_echo(char **av)
{
    int no_nl;
    int i;

    no_nl = 0;
    i = 1;
    while (is_n_chain_option(av[i]))
    {
        no_nl = 1;
        i++;
    }
    while (av[i])
    {
        ft_putstr_fd(av[i], 1);
        if (av[i+1])
            ft_putstr_fd(" ", 1);
        i++;
    }
    if (no_nl == 0)
        write(1, "\n", 1);
    exit(EXIT_SUCCESS);
}
