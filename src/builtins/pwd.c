#include "../../include/minishell.h"

void	ft_pwd(char **args)
{
	char	*pwd;

	(void) args;
	pwd = getcwd(NULL, 0);
	if (pwd)
		printf("%s\n", pwd);
	free(pwd);
}
