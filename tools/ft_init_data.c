#include "../builtins.h"

char    *get_env_name(char *env_var)
{
    int i;
    char *name;

    i = 0;
    name = NULL;
    if (!env_var || !env_var[0] || env_var[0] == '=')
        return (NULL);
    while (env_var[i])
    {
        if (env_var[i] == '=' || (env_var[i] == '+' && env_var[i+1] == '='))
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
    if (!env_var[i])
        return (NULL);
    return (strdup(env_var + i + 1)); // zakaria=\0
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

void    ft_init_data(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    g_env = ft_fill_env(env);
    
}
