#include "../builtins.h"

void    pwd(int ac, char **av)
{
    char    path[PATH_MAXO];
    int     prev_errno;

    if (ac > 1)
    {
        ft_putstr_fd("pwd: too many arguments\n", 2);
        exit(EXIT_FAILURE);
    }
    
    if (getcwd(path, PATH_MAXO) != NULL)
        printf("%s\n", path);
    else
    {
        prev_errno = errno;
        ft_putstr_fd("pwd: ", 2);
        ft_putstr_fd(strerror(prev_errno), 2);
        ft_putstr_fd("\n", 2);
    }
    exit(EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    pwd(ac, av);
}
