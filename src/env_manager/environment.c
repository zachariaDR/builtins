/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc@student.1337.ma <zadriouc>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 01:51:48 by msennane          #+#    #+#             */
/*   Updated: 2024/11/28 14:34:38 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env_var	*create_env_var(char *key, char *value)
{
	t_env_var	*new;

	new = malloc(sizeof(t_env_var));
	if (!new)
		return (NULL);
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

int	update_env_var(t_env_var *env_var_list, t_env_var *new_nod)
{
	t_env_var	*tmp;
	char		*new_value;

	tmp = env_var_list;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, new_nod->key) == 0)
		{
			if (!new_nod->value)
				return (free_env_node(new_nod), 1);
			new_value = ft_strdup(new_nod->value);
			if (!new_value)
				return (free_env_node(new_nod), 1);
			free(tmp->value);
			tmp->value = new_value;
			free_env_node(new_nod);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	insert_env_var(t_env_var **env_var_list, t_env_var *new_nod)
{
	t_env_var	*curr;
	t_env_var	*prev;

	if (update_env_var(*env_var_list, new_nod))
		return ;
	if (!*env_var_list)
	{
		*env_var_list = new_nod;
		return ;
	}
	if (ft_strcmp(new_nod->key, (*env_var_list)->key) < 0)
	{
		new_nod->next = *env_var_list;
		*env_var_list = new_nod;
		return ;
	}
	curr = *env_var_list;
	prev = NULL;
	while (curr && ft_strcmp(new_nod->key, curr->key) >= 0)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = new_nod;
	new_nod->next = curr;
}

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

static void	extract_and_push(t_env_var **env_var_list, char *env_var)
{
	char		*key;
	char		*value;
	char		*equal;
	t_env_var	*new_nod;

	equal = ft_strchr(env_var, '=');
	if (!equal)
	{
		new_nod = create_env_var(ft_strdup(env_var), NULL);
	}
	else
	{
		key = ft_substr(env_var, 0, equal - env_var);
		value = ft_strdup(equal + 1);
		if (ft_strcmp(key, "OLDPWD") == 0)
		{
			new_nod = create_env_var(key, NULL);
			free(key);
		}
		else
			new_nod = create_env_var(key, value);
	}
	insert_env_var(env_var_list, new_nod);
}

void	init_env_var(t_env_var **env_var_list, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		extract_and_push(env_var_list, envp[i]);
		i++;
	}
}
