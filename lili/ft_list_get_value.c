#include "ft_a_list.h"

char	*ft_list_get_value(t_env *begin_list, char *value, int (*cmp)())
{
    return (ft_list_find(begin_list, value, 'v', cmp)->value);
}
