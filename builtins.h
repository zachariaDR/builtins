/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc@student.1337.ma <zadriouc>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:16:59 by zadriouc          #+#    #+#             */
/*   Updated: 2024/10/21 18:32:31 by zadriouc@st      ###   ########.fr       */
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

extern t_env	*g_env;


void    ft_putstr_fd(const char *str, int fd);
int		ft_atoi(const char *str);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isdigit(int i);
void	ft_putendl_fd(char *s, int fd);
// char	*ft_strchr(const char *s, int i);
char	*ft_strjoin(char *s1, char *s2);
// int		ft_strlen(const char *str);
// int		strncmp(const char *s1, char *s2, size_t n);
void    ft_putstr_fd(const char *str, int fd);
char	*ft_strcjoin(char *s1, char c);


int     ft_matlen(char **mat);
t_env	*ft_fill_env(char **env);
void	ft_init_data(int ac, char **av, char **env);
char    *get_env_name(char *env_var);
char    *get_env_value(char *env_var);
//		builitins
void    ft_env(char **arg);
void    ft_unset(char **arg);
void    ft_export(char **arg);


#endif