/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:01:46 by josantos          #+#    #+#             */
/*   Updated: 2022/03/16 12:12:22 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_builtin(t_cmd *command)
{
	if (!command->suffix)
		chdir(scan_envp("HOME", NULL));
	else if (ft_strncmp(command->suffix->content, "-",
			ft_strlen(command->suffix->content)) == 0)
	{
		if (opendir(scan_envp("OLDPWD", NULL)))
			chdir(scan_envp("OLDPWD", NULL));
		else
			return (BUILTIN_FAILURE);
	}
	else if (opendir(command->suffix->content))
		chdir(command->suffix->content);
	else
		return (BUILTIN_FAILURE);
	scan_envp("OLDPWD", ft_strdup(scan_envp("PWD", NULL)));
	scan_envp("PWD", getcwd(NULL, 0));
	printf("%s\n", scan_envp("PWD", NULL));
	return (SUCCESS);
}
