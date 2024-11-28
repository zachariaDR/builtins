/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc@student.1337.ma <zadriouc>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 01:47:29 by msennane          #+#    #+#             */
/*   Updated: 2024/11/28 15:07:17 by zadriouc@st      ###   ########.fr       */
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


# define PATH_MAXO 4096

typedef struct s_env_var
{
	char				*key;
	char				*value;
	struct s_env_var	*next;
}						t_env_var;

//		builtins
void    ft_env(t_env_var *env_vars);
void	ft_export(t_env_var **env_vars, char **args);
void	ft_unset(t_env_var **env_vars, char **args);
void	ft_pwd(char **args);
void	ft_cd(t_env_var **env_vars, char **args);
void    ft_echo(int ac, char **av);
void 	ft_exit(int ac, char **av);


#endif
