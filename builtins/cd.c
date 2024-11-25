#include "../builtins.h"

static void ft_puterror(char *arg)
{
    ft_putstr_fd("bash: cd: '", 2);
    ft_putstr_fd(arg, 2);
    ft_putstr_fd("': No such file or directory\n", 2);
}

void ft_puterror2(char *arg)
{
    ft_putstr_fd("bash: cd: ", 2);
    ft_putstr_fd(arg, 2);
    ft_putstr_fd(": not set\n", 2);
}

void ft_puterror3(char *arg, char *arg2)
{
    ft_putstr_fd("bash: cd: ", 2);
    ft_putstr_fd(arg, 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(arg2, 2);
    ft_putstr_fd("\n", 2);
}

void	set_oldpwd(void)
{
    t_env   *trav;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return ;
    trav = g_env;
	while (trav)
	{
		if (!strncmp("OLDPWD", trav->name, 6))
		{
			free(trav->value);
            trav->value = strdup(cwd);
		}
		trav = trav->next;
	}
	free(cwd);
}

void	set_pwd(void)
{
    t_env   *trav;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return ;
    trav = g_env;
	while (trav)
	{
		if (!strncmp("PWD", trav->name, 6))
		{
			free(trav->value);
            trav->value = strdup(cwd);
		}
		trav = trav->next;
	}
	free(cwd);
}

int	check_home(void)
{
    t_env   *trav;

    trav = g_env;
	while (trav)
	{
		if (!strncmp("HOME", trav->name, 4))
				return (1);
		trav = trav->next;
	}
	return (0);
}

void	ft_chdir(char *path)
{
	int	i;

	set_oldpwd();
	i = chdir(path);
	if (i)
	{
        ft_puterror(path);
		return ;
	}
	printf("%s\n", path);
	set_pwd();
	free(path);
}

void	cd_oldpwd(void)
{
	char	*path;

    path = ft_list_get_value(g_env, "OLDPWD");
	if (!path)
        ft_puterror("OLDPWD");
	else
		ft_chdir(path);
}

void	cd_home(void)
{
	char	*path;
	int		i;

	if (!check_home())
        ft_puterror("HOME");
	else
	{
		set_oldpwd();
        path = ft_list_get_value(g_env, "HOME");
		// path++; 									fix the issue of the missing '=' in value node 
		i = chdir(path);
		if (i)
		{
            ft_puterror(path);
			return ;
		}
		set_pwd();
		free(path);
	}
}

void	ft_cd(char **args)
{
	char	*cwd;
	int		i;

	cwd = getcwd(NULL, 0);
	if (!args[1])
		cd_home();
	else if (!strcmp(args[1], "-"))
		cd_oldpwd();
	else if (strcmp(args[1], "."))
	{
		set_oldpwd();
		i = chdir(args[1]);
		if (i == -1)
		{
            ft_puterror3(args[1], strerror(errno));;
			free(cwd);
			return ;
		}
		set_pwd();
	}
	else if (!cwd)
		ft_putstr_fd("cd: error retrieving current directory: getcwd:\
		cannot access parent directories: No such file or directory\n", 2);
	free(cwd);
}
