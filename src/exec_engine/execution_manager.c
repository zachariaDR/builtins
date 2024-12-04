/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc@student.1337.ma <zadriouc>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 23:46:23 by msennane          #+#    #+#             */
/*   Updated: 2024/12/04 00:49:51 by zadriouc@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//			inserted echo + exit + env 
static void	execute_builtin_command(t_exec *exec_cmd, t_shell_context *context,
		int *exit_status)
{
	int		status;

	if (ft_strcmp(exec_cmd->argv[0], "echo") == 0)
	{
		// Implement echo functionality
		ft_echo(exec_cmd->argv);
		printf("\n");
		*exit_status = 0;
	}
	else if (ft_strcmp(exec_cmd->argv[0], "exit") == 0)
	{
		// Implement exit functionality
		ft_exit(exec_cmd->argv, &status);
		// status = 0;
		// if (exec_cmd->argv[1])
		// 	status = atoi(exec_cmd->argv[1]);
		terminate_cleanly(context, status);
	}
	else if (ft_strcmp(exec_cmd->argv[0], "env") == 0)
	{
		// Implement env functionality
		ft_env(context->env_vars);
		// for (int i = 0; context->envp[i]; i++)
		// 	printf("%s\n", context->envp[i]);
		*exit_status = 0;
	}
	else if (ft_strcmp(exec_cmd->argv[0], "export") == 0)
	{
		// Implement export functionality
		// ft_export(&(context->env_vars), exec_cmd->argv);
		// Placeholder: Just set exit_status to 0
		*exit_status = 0;
	}
	else if (ft_strcmp(exec_cmd->argv[0], "unset") == 0)
	{
		// Implement unset functionality
		// ft_unset(&(context->env_vars), (exec_cmd->argv));
		// Placeholder: Just set exit_status to 0
		*exit_status = 0;
	}
	else if (ft_strcmp(exec_cmd->argv[0], "pwd") == 0)
	{
		// Implement pwd functionality
		ft_pwd(exit_status, exec_cmd->argv[0]);
	}
	else
	{
		print_exec_error(exec_cmd->argv[0], "Unknown builtin command");
		*exit_status = 1;
	}
}
