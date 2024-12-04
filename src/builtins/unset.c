#include "../../include/minishell.h"

static void ft_puterror(char *arg)
{
    ft_putstr_fd("bash: unset: '", 2);
    ft_putstr_fd(arg, 2);
    ft_putstr_fd("': not a valid identifier\n", 2);
}

static int valid_char(char c)
{
    return (c && ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9')
			|| c == '_'));
}

int	validate(char *str)
{
	size_t	i;

	i = 0;
	while (valid_char(str[i]))
		i++;
	if (i != ft_strlen(str))
		return (0);
	return (1);
}

void	ft_unset(t_env_var **env_vars, char **args)
{
	int	i;
	t_env_var *node;
	
	i = 1;
	while (args[i])
	{
		if (!validate(args[i]))
            ft_puterror(args[i]);
		else
		{
			node = create_env_var(ft_strdup(args[i]), NULL);
			remove_env_var(env_vars, node);
		}
		i++;
	}
}
