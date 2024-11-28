/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc@student.1337.ma <zadriouc>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 01:47:29 by msennane          #+#    #+#             */
/*   Updated: 2024/11/28 02:55:07 by zadriouc@st      ###   ########.fr       */
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



void    ft_print_list(t_env_var**list);
int     list_is_empty(t_env_var**list);

//		builitins
void    ft_env(char **arg);
void    ft_unset(char **arg);
void    ft_export(char **arg);


#endif
