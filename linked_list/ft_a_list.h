#ifndef FT_A_LIST_H
#define FT_A_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include <strings.h>

typedef struct	s_env
{
	char			*name;
	char			*value;
	struct 	s_env	*next;
}				t_env;

t_env 	*ft_create_elem(char *name, char *value);

//--------- push fucntions ----------
void    ft_list_push_back(t_env **begin_list, char *name, char *value);
void    ft_list_push_post_nth(t_env **begin_list, char *name, char *value, char *pos);
void    ft_list_push_pre_nth(t_env **begin_list, char *name, char *value,void *pos);
t_env 	*ft_list_push_front(t_env *begin_list, char *name, char *value);
t_env 	*ft_list_push_strs(int size, char **strs);

//-------- get functinos -----------
t_env 	*ft_list_last(t_env *begin_list);
t_env 	*ft_list_at_index(t_env *begin_list, unsigned int nbr);
// t_env 	*ft_list_find(t_env *begin_list, void *data_ref, int (*cmp)());
t_env 	*ft_list_find(t_env *begin_list, void *data_ref, char x, int (*cmp)());
char	*ft_list_get_name(t_env *begin_list, char *name, int (*cmp)());
char	*ft_list_get_value(t_env *begin_list, char *value, int (*cmp)());
int 	ft_list_size(t_env *begin_list);


//-------- set functions ----------
void    ft_list_set_value(t_env *begin_list, char *name, char *n_value, int (*cmp)());


//-------- remove functions --------
void	ft_list_clear_bonus(t_env **lst, void (*del)(void *));
void    ft_list_clear(t_env **begin_list, void (*free_fct)(void *));
void    ft_list_del_last(t_env **begin_list, void (*free_fct)(void *));
void    ft_list_del_first(t_env **begin_list, void (*free_fct)(void *));
void    ft_list_del_nth(t_env **begin_list, void *data, void (*free_fct)(void *));



void    ft_print_list(t_env **list);
int     list_is_empty(t_env **list);

#endif
