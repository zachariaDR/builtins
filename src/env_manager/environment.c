/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc@student.1337.ma <zadriouc>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 01:51:48 by msennane          #+#    #+#             */
/*   Updated: 2024/12/04 00:52:57 by zadriouc@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//		function modified
void	init_env_var(t_env_var **env_var_list, char **envp)
{
	int	i;
	char *oldpwd_path;
	t_env_var *node;
	
	i = 0;
	while (envp[i])
	{
		extract_and_push(env_var_list, envp[i]);
		i++;
	}
	
	// Initialize the value of OLDPWD with the value of PWD     <--- this to hundle the issue of the case of (cd - ) when it's the first command to ran in the shell
	oldpwd_path = ft_strdup(get_env_value("PWD", *env_var_list));   //  added line
	node = create_env_var(ft_strdup("OLDPWD"), oldpwd_path);		//	added line
	update_env_var(*env_var_list, node);
								//  added line
	// Increment SHLVL after initialization
	increment_shell_level(*env_var_list);
}

//		extra funtion added									<--    for unset builtin
void	remove_env_var(t_env_var **env_var_list, t_env_var *del_nod)
{
	t_env_var	*curr;
	t_env_var	*prev;

	if (*env_var_list == NULL)
	{
		free_env_node(del_nod);
		return ;
	}
	curr = *env_var_list;
	prev = NULL;
	if (ft_strcmp(del_nod->key, (*env_var_list)->key) == 0)
	{
		*env_var_list = curr->next;
		free_env_node(curr);
		free_env_node(del_nod);
		return ;
	}
	while (curr && ft_strcmp(del_nod->key, curr->key) != 0)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	free_env_node(curr);
	free_env_node(del_nod);
}
