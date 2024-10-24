#include "../builtins.h"

static void ft_puterror(char *arg)
{
    ft_putstr_fd("bash: export: '", 2);
    ft_putstr_fd(arg, 2);
    ft_putstr_fd("': not a valid identifier\n", 2);
}

int is_numeric(char c)
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

int	valid_ident(char *str, int *op)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=' && str[i] != '+')
	{
		if (!valid_char(str[i]))
		{
			// printf("NNNNNNNNN\n\n\n\n\n\n");

			ft_puterror(str);
			return (0);
		}
		i++;
	}
	if (i == 0 || is_numeric(str[0]) || (str[i] == '+' && str[i+1] != '='))
	{
	    ft_puterror(str);
		return (0);
	}
	if (str[i] == '=')
		*op = 1;
	else if (str[i] == '+')
		*op = 2;
	return (1);
}

char    *var_exist(char *str)
{
	int	j;
    t_env   *trav;

	j = 0;
	while (str[j])
	{
		if (str[j] == '=' || str[j] == '+')
			break ;
		j++;
	}
    trav = g_env;
	while (trav)
	{
		if (!strncmp(str, trav->name, j))
			if (trav->value[0] == '=' || !(trav->value[0]))
				return (trav->name);
		trav = trav->next;
	}
	return (NULL);
}

void	export_var(char **args)
{
	int	    i;
	int		valid;
	char    *name;
	char	*concat;

	i = 1;
	while (args[i])
	{
		if (valid_ident(args[i], &valid))
		{
			// printf("HIIIIIIIIIIIi\n\n\n\n\n");
			name = var_exist(args[i]);
			if (!name)
                ft_list_push_back(&g_env, get_env_name(args[i]), get_env_value(args[i]));
			else
			{
				// it's not even enter this place
				printf("\n\n\n\n\n valid = %d    \n\n\n\n\n", valid);
				if (strchr(args[i], '=') && valid == 1)
				{
			printf("HIIIIIIIIIIIi\n\n\n\n\n");

                	ft_list_set_value(g_env, name, get_env_value(args[i]));
				}
				else if (strchr(args[i], '=') && valid == 2)
				{

					concat = get_env_value(args[i]);
					ft_list_set_value(g_env, name, ft_strjoin(ft_list_get_value(g_env, name), concat + 1));
					free(concat);
				}
			}
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
		if (!strchr(trav->value, '='))
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
