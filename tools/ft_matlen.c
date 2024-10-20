#include "builtins.h"

int     ft_matlen(char **mat)
{
    int i;

    i = 0;
    while (mat[i])
        i++;
    return (i);
}
