#include "../../include/minishell.h"

void	ft_pwd(int *exit_status, char *argv)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		printf("%s\n", pwd);
		free(pwd);
		*exit_status = 0;
	}
	else
	{
		print_exec_error(argv, "Unable to get current directory");
		*exit_status = 1;
	}
}

