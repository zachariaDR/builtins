/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc@student.1337.ma <zadriouc>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 01:47:29 by msennane          #+#    #+#             */
/*   Updated: 2024/12/04 00:04:43 by zadriouc@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "environment.h"

//		builtins
void    ft_env(t_env_var *env_vars);
void	ft_export(t_env_var **env_vars, char **args);
void	ft_unset(t_env_var **env_vars, char **args);
void	ft_pwd(int *exit_status, char *argv);
void	ft_cd(t_env_var **env_vars, char **args);
void    ft_echo(char **av);
void 	ft_exit(char **av, int *exit_status);


#endif
