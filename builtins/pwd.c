#include "../builtins.h"

void	re_pwd(char **args)
{
	char	*pwd;

	(void) args;
	pwd = getcwd(NULL, 0);
	if (pwd)
		printf("%s\n", pwd);
	free(pwd);
}
