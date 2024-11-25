#ifndef FT_A_LIST_H
#define FT_A_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct	s_env
{
	char			*name;
	char			*value;
	struct 	s_env	*next;
}				t_env;

t_env 	*ft_create_elem(char *name, char *value);

//--------- push fucntions ----------
void    ft_list_push_back(t_env **begin_list, char *name, char *value);

//-------- get functinos -----------
t_env 	*ft_list_last(t_env *begin_list);
t_env 	*ft_list_get(t_env *begin_list, void *data_ref, char x);
char	*ft_list_get_value(t_env *begin_list, char *name);
int 	ft_list_size(t_env *begin_list);

//-------- set functions ----------
void    ft_list_set_value(t_env *begin_list, char *name, char *n_value);

//-------- remove functions --------
void	ft_list_clear(t_env **lst, void (*del)(void *));
void    ft_list_del_last(t_env **begin_list, void (*free_fct)(void *));
void    ft_list_del_first(t_env **begin_list, void (*free_fct)(void *));
void    ft_list_del(t_env **begin_list, void *data, void (*free_fct)(void *));


void    ft_print_list(t_env **list);
int     list_is_empty(t_env **list);

#endif
