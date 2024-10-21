#include "ft_a_list.h"

t_env *ft_create_elem(char *data, char *value)
{
	t_env *n_new;

    n_new = (t_env *)malloc(sizeof(t_env));
    if (!n_new)
        return (NULL);
    n_new->name = data;
    n_new->value = value;
    n_new->next = NULL;
    return (n_new);	
}
