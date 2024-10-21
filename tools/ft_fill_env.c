#include "../builtins.h"

char    *get_env_name(char *env_var)
{
    int i;
    char *name;

    i = 0;
    while (env_var[i])
    {
        if (env_var[i] == '=')
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
        if (env_var[i] == '=')
            break;
        i++;
    }
    return (strdup(env_var + i)); 
}

t_env   *ft_fill_env(char **env)
{
    t_env *new_env;
    char  *name;
    char  *value;
    int  i;

    new_env = NULL;
    i = 0;
    while (env[i])
    {
        name = get_env_name(env[i]);
        value = get_env_value(env[i]);
        ft_list_push_back(&new_env, name, value);
        i++;
    }

    return (new_env);
}
