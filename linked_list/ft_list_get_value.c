#include "ft_a_list.h"

char	*ft_list_get_value(t_env *begin_list, char *name)
{
    return (ft_list_get(begin_list, name, 'n')->value);
}
