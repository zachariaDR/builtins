#include "ft_a_list.h"

char	*ft_list_get_name(t_env *begin_list, char *name, int (*cmp)())
{
    return (ft_list_find(begin_list, name, 'n', cmp)->name);
}