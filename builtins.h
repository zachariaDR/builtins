/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc@student.1337.ma <zadriouc>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:16:59 by zadriouc          #+#    #+#             */
/*   Updated: 2024/10/20 19:42:43 by zadriouc@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <limits.h>

# include "linked_list/ft_a_list.h"

# define PATH_MAXO 4096

// typedef struct	s_env
// {
// 	char			*name;
// 	char			*value;
// 	struct 	s_env	*next;
// 	struct 	s_env	*prev;
// }				t_env;

// typedef struct s_list
// {
// 	char			*data;
// 	struct s_list 	*next;
// }				t_list;

typedef struct s_bi
{
	char	*name;
	void	(*func)(char **);
}				t_bi;

typedef struct s_exec
{
	t_bi	bi[7];
	t_env 	*env;
}				t_exec;


extern t_env	*g_env;

// extern char	**g_env;
// t_exec	g_exec;


void    ft_putstr_fd(const char *str, int fd);
int		ft_atoi(const char *str);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isdigit(int i);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strchr(const char *s, int i);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, char *s2, size_t n);
void    ft_putstr_fd(const char *str, int fd);
char	*ft_strcjoin(char *s1, char c);


int     ft_matlen(char **mat);
t_env	*ft_fill_env(char **env);
void	ft_init_data(int ac, char **av, char **env);
char    *get_env_name(char *env_var);
char    *get_env_value(char *env_var);
//		builitins
void    ft_env(char **arg);
void    ft_unset(char *arg);


#endif