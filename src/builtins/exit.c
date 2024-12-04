#include "../../include/minishell.h"

static void ft_puterror(char *arg)
{
    ft_putstr_fd("minishell: exit: ", 2);
    ft_putstr_fd(arg, 2);
    ft_putstr_fd(": numeric argument required\n", 2);
}

static int ft_args_len(char **av)
{
    int i;

    i = 0;
    while (av[i])
        i++;
    return (i);
}

static int ft_is_numeric(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

void ft_exit(char **av, int *exit_status)
{
    int ac;

    ac = ft_args_len(av);
    ft_putstr_fd("exit\n", 1);
    if (ac == 1)
        *exit_status = 0;
    if (!ft_is_numeric(av[1]))
    {
        ft_puterror(av[1]);
        *exit_status = 2;
    }
    if (ac == 2 && ft_is_numeric(av[1]))
        *exit_status = atoi(av[1]);
    if (ac > 2)
    {
        ft_putstr_fd("minishell: exit: too many arguments\n", 2);
        *exit_status = 1;
    }
}
