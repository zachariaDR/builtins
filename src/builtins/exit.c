#include "../../include/minishell.h"

static void ft_puterror(char *arg)
{
    ft_putstr_fd("bash: exit: ", 2);
    ft_putstr_fd(arg, 2);
    ft_putstr_fd(": numeric argument required\n", 2);
}

int ft_is_numeric(char *str)
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

void ft_exit(int ac, char **av)
{
    ft_putstr_fd("exit\n", 1);
    if (ac == 1)
        exit(EXIT_SUCCESS);
    if (!ft_is_numeric(av[1]))
    {
        ft_puterror(av[1]);
        exit(2);
    }
    if (ac ==2 && ft_is_numeric(av[1]))
        exit(atoi(av[1]));
    if (ac > 2)
    {
        ft_putstr_fd("bash: exit: too many arguments\n", 2);
        exit(EXIT_FAILURE);
    }
}