#include "ft_a_list.h"


t_env *ft_create_elem(char *data, char *value)
{
	t_env *new;

    
    new = (t_env *)malloc(sizeof(t_env));
    if (!new)
        return (NULL);
    new->name = data;
    new->value = value;
    new->next = NULL;
    return (new);	
}
