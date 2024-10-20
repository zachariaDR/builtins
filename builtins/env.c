#include "../builtins.h"

// int main(int ac, char **av, char **env)
// {
//     // char *path;

//     // path = getenv("PWD");
//     // if (path)
//     //     printf("%s\n", path);
//     // else
//     //     printf("pwd: path not found!\n");

//     int i = 0;
//     while (env[i])
//     {
//         printf("%s\n", env[i]);
//         i++;
//     }

//     // setenv("SAKA", "loser_ofc", 1);
//     // system("ls");
//     return (0);
// }


void    ft_env(char **arg)
{
    (void)arg;
    ft_print_list(&g_env);
}
