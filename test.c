#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char    *get_env_name(char *env_var)
{
    int i;
    char *name;

    i = 0;
    while (env_var[i])
    {
        if (env_var[i] == '=' || env_var[i] == '+')
            break;
        i++;
    }
    name = (char *)malloc((sizeof(char) * i) + 1);
    name = strncpy(name, env_var, i);
    return (name); 
}

char    *get_env_value(char *env_var)
{
    int i;
    char *value;

    i = 0;
    while (env_var[i])
    {
        if (env_var[i] == '=' )
            break;
        i++;
    }
    return (strdup(env_var + i + 1));
}

int main (void)
{
    char env[] = "ZAKARIA";
    char *name;
    char *value;

    name = NULL;
    value = NULL;
    name = get_env_name(env);
    value = get_env_value(env);
    if (value != NULL)
        printf(" %s=%s \n", name, value);
    return (0);
}
