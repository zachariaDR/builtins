#include "../../include/minishell.h"

static void ft_puterror(char *arg)
{
    ft_putstr_fd("bash: export: '", 2);
    ft_putstr_fd(arg, 2);
    ft_putstr_fd("': not a valid identifier\n", 2);
}

int is_c_numeric(char c)
{
    return (c >= '0' && c <= '9');
}

static	int valid_char(char c)
{
    return (c && ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9')
			|| c == '_'));
}

int	valid_ident(char *str, char *op)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=' && str[i] != '+')
	{
		if (!valid_char(str[i]))
		{
			ft_puterror(str);
			return (0);
		}
		i++;
	}
	if (i == 0 || is_c_numeric(str[0]) || (str[i] == '+' && str[i+1] != '='))
	{
	    ft_puterror(str);
		return (0);
	}
	if (str[i] == '=')
		*op = '=';
	else if (str[i] == '+')
		*op = '+';
	return (1);
}

char    *var_exist(t_env_var *env_vars ,char *str)
{
	int	j;
    t_env_var   *tmp;

	j = 0;
	while (str[j])
	{
		if (str[j] == '=' || str[j] == '+')
			break ;
		j++;
	}
    tmp = env_vars;
	while (tmp)
	{
		if (!strncmp(str, tmp->key, j))
				return (tmp->key);
		tmp = tmp->next;
	}
	return (NULL);
}

void	export_var(t_env_var **env_vars, char **args)
{
	int	    	i;
	char		valid;
	char    	*name;
	t_env_var	*updated_node;

	i = 1;
	while (args[i])
	{
		if (valid_ident(args[i], &valid))
		{
			name = var_exist(*env_vars, args[i]);
			if (!name)
			{
				extract_and_push(env_vars, args[i]); // <-- done!
			}
			else
			{
				if (strchr(args[i], '=') && valid == '=')
				{
					updated_node = create_env_var(name, strdup(strchr(args[i], '=') + 1)); // <-- done!
					update_env_var(*env_vars, updated_node);  // <-- done!
				}
				else if (strchr(args[i], '=') && valid == '+')
				{
					updated_node = create_env_var(name, ft_strjoin(get_env_value(name, *env_vars), strchr(args[i], '=') + 1)); // <-- done!
					update_env_var(*env_vars, updated_node);  // <-- done!
				}
			}
		}
		i++;
	}
}

void	export_declare(t_env_var *env_vars)
{
	t_env_var	*list;
	
	list = env_vars;
	while (list)
	{
		if (!(list->value))
			printf("declare -x %s\n", list->key);
		else
	        printf("declare -x %s=%c%s%c\n",list->key, '"', list->value, '"');
		list = list->next;
	}
}

void	ft_export(t_env_var **env_vars, char **args)
{
	if (args[1])
	{
		export_var(env_vars, args);
	}
	else
	{
		export_declare(*env_vars);
	}
}
