/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void-shell-utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc@student.1337.ma <zadriouc>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:39:02 by msennane          #+#    #+#             */
/*   Updated: 2024/12/04 00:50:20 by zadriouc@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//		inserted cd + export + unset
void	run_built_in_command(t_exec *cmd, t_env_var **env_list,
		int *exit_status)
{
	(void)env_list;
	(void)exit_status;
	if (ft_strcmp(cmd->argv[0], "cd") == 0)
	{
		// run_cd(cmd, env_var_list, exit_status);
		ft_cd(env_list, cmd->argv);
	}
	else if (ft_strcmp(cmd->argv[0], "export") == 0)
	{
		// run_export(cmd, env_var_list, exit_status);
		ft_export(env_list, cmd->argv);
	}
	else if (ft_strcmp(cmd->argv[0], "unset") == 0)
	{
		// run_unset(cmd, env_var_list, exit_status);
		ft_unset(env_list, cmd->argv);
	}
}
