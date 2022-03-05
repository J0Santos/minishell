/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:58:25 by josantos          #+#    #+#             */
/*   Updated: 2022/03/05 21:59:34 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define SUCCESS 			0
# define GENERAL_FAILURE	1
# define BUILTIN_FAILURE	2
# define COMMAND_FAILURE	126
# define COMMAND_NOT_FOUND	127
# define CONTROL_C 			130

typedef struct s_export_vars
{
	char	*var_name;
	char	*var_val;
}	t_exp_vars;

int			cd_builtin(t_cmd *command);
int			echo_builtin(t_cmd *command);
int			env_builtin(t_cmd *command);
int			exit_builtin(t_cmd *command);
int			export_builtin(t_cmd *command);
int			pwd_builtin(t_cmd *command);
int			unset_builtin(t_cmd *command);

#endif /* BUILTINS_H */
