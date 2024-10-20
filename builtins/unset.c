#include "../builtins.h"

void ft_puterror(char *arg)
{
    ft_putstr_fd("bash: unset: '", 2);
    ft_putstr_fd(arg, 2);
    ft_putstr_fd("': not a valid identifier\n", 2);
}

int valid_char(char c)
{
    return (c && ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9')
			|| c == '_'));
}

int	validate(char *str)
{
	int	i;

	i = 0;
	while (valid_char(str[i]))
		i++;
	if (i != ft_strlen(str))
		return (0);
	return (1);
}

void	ft_unset(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (!validate(args[i]))
            ft_puterror(args[i]);
		else
            ft_list_del_nth(&g_env, args[i],free);
		i++;
	}
}
