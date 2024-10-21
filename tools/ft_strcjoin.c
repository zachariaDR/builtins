#include "../builtins.h"

char	*ft_strcjoin(char *s1, char c)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (strlen(s1) + 2));
	if (!str)
		return (0);
	i = 1;
	str[0] = c;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
