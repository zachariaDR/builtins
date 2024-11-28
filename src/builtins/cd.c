#include "../../include/minishell.h"

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

void	set_env_var(const char *key, t_env_var *env_vars)
{
	char		*cwd;
	t_env_var 	*node;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return ;
	node = create_env_var(ft_strdup(key), cwd);
	update_env_var(env_vars, node);
}

int	check_home(t_env_var *env_vars)
{
    t_env_var   *tmp;

    tmp = env_vars;
	while (tmp)
	{
		if (!strncmp("HOME", tmp->key, 4))
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_chdir(t_env_var *env_vars, char *path)
{
	int	i;

	set_env_var("OLDPWD", env_vars);
	i = chdir(path);
	if (i)
	{
        ft_puterror(path);
		return ;
	}
	printf("%s\n", path);
	set_pwd("PWD", env_vars);
	free(path);
}

void	cd_oldpwd(t_env_var *env_vars)
{
	char	*path;

    path = get_env_value("OLDPWD", env_vars);
	if (!path)
        ft_puterror("OLDPWD");
	else
		ft_chdir(env_vars, path);
}

void	cd_home(t_env_var *env_vars)
{
	char	*path;
	int		i;

	if (!check_home(env_vars))
        ft_puterror("HOME");
	else
	{
		set_env_var("OLDPWD", env_vars);
        path = get_env_value("HOME", *env_vars);
		i = chdir(path);
		if (i)
		{
            ft_puterror(path);
			return ;
		}
		set_env_var("PWD", env_vars);
		free(path);
	}
}

void	ft_cd(t_env_var **env_vars, char **args)
{
	char	*cwd;
	int		i;

	cwd = getcwd(NULL, 0);
	if (!args[1])
		cd_home(*env_vars);
	else if (!strcmp(args[1], "-"))
		cd_oldpwd(*env_vars);
	else if (strcmp(args[1], "."))
	{
		set_env_var("OLDPWD", *env_vars);
		i = chdir(args[1]);
		if (i == -1)
		{
            ft_puterror3(args[1], strerror(errno));;
			free(cwd);
			return ;
		}
		set_env_var("PWD", *env_vars);
	}
	else if (!cwd)
		ft_putstr_fd("cd: error retrieving current directory: getcwd:\
		cannot access parent directories: No such file or directory\n", 2);
	free(cwd);
}
