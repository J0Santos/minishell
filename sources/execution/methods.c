/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <josantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:23:06 by josantos          #+#    #+#             */
/*   Updated: 2022/01/28 14:49:06 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_builtins(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->name, "cd", 2) && ft_strlen(cmd->name) == 2)
		cd_builtin(cmd);
	if (!ft_strncmp(cmd->name, "echo", 4) && ft_strlen(cmd->name) == 4)
	{
		echo_builtin(cmd);
	}
	else if (!ft_strncmp(cmd->name, "env", 3) && ft_strlen(cmd->name) == 3)
		env_builtin();
	else if (!ft_strncmp(cmd->name, "pwd", 3) && ft_strlen(cmd->name) == 3)
		pwd_builtin();
}

void	execute_method(t_cmd *cmd)
{
	/*t_ctrl	*controllers;

	controllers = init_controllers(NULL);*/
	do_builtins(cmd);
}