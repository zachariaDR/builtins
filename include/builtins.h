/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc@student.1337.ma <zadriouc>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 01:47:29 by msennane          #+#    #+#             */
/*   Updated: 2024/11/28 15:15:11 by zadriouc@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "environment.h"

//		builtins
void    ft_env(t_env_var *env_vars);
void	ft_export(t_env_var **env_vars, char **args);
void	ft_unset(t_env_var **env_vars, char **args);
void	ft_pwd(char **args);
void	ft_cd(t_env_var **env_vars, char **args);
void    ft_echo(int ac, char **av);
void 	ft_exit(int ac, char **av);


#endif
