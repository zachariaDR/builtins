#include "../builtins.h"

void ft_puterror(char *arg)
{
    ft_putstr_fd("bash: export: '", 2);
    ft_putstr_fd(arg, 2);
    ft_putstr_fd("': not a valid identifier\n", 2);
}

int is_numeric(char c)
{
    return (c >= '0' && c <= '9');
}

int valid_char(char c)
{
    return (c && ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9')
			|| c == '_'));
}

int	valid_ident(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (!valid_char(str[i]))
		{
			ft_puterror(str);
			return (0);
		}
		i++;
	}
	if (i == 0|| is_numeric(str[0]))
	{
	    ft_puterror(str);
		return (0);
	}
	return (1);
}

char    *var_exist(char *str)
{
	int	j;
    t_env   *trav;

	j = 0;
	while (str[j])
	{
		if (str[j] == '=')
			break ;
		j++;
	}
    trav = g_env;
	while (trav)
	{
		if (!ft_strncmp(str, trav->name, j))
			if (trav->value[0] == '=' || !(trav->value[0]))
				return (trav->name);
		trav = trav->next;
	}
	return (NULL);
}

void	export_var(char **args)
{
	int	    i;
	char    *name;

	i = 1;
	while (args[i])
	{
		if (valid_ident(args[i]))
		{
			name = var_exist(args[i]);
			if (!name)
                ft_list_push_back(&g_env, get_env_name(args[i]), get_env_value(args[i]));
			else
                ft_list_set_value(&g_env, name, get_env_value(args[i]), strcmp);
		}
		i++;
	}
}

void	sort_env(void)
{
	t_env	*tmp;
    t_env   *trav;
    t_env   *trav_n;

	trav = g_env;
	while (trav)
	{
		trav_n = trav->next;
		while (trav_n)
		{
			if (strcmp(trav->name, trav_n->name) > 0)
			{
				tmp->name = trav->name;
				tmp->value = trav->value;
				trav->name = trav_n->name;
				trav->value = trav_n->value;
				trav_n->name = tmp->name;
				trav_n->value = tmp->value;
			}
			trav_n = trav_n->next;
		}
		trav = trav->next;
	}
}

void	export_declare(void)
{
    t_env *trav;

    trav = g_env;
	while (trav)
	{
		if (!ft_strchr(trav->value, '='))
			printf("declare -x %s\n", trav->name);
		else
	        printf("declare -x %c%s%c\n", '"', trav->name, '"');
		trav = trav->next;
	}
}

void	ft_export(char **args)
{
	if (args[1])
	{
		export_var(args);
		sort_env();
	}
	else
		export_declare();
}
