/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:45:20 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/10 10:01:57 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * This function initializes the main struct of the program - (t_ctrl *)
 * controllers, once called by the main() function.
 * If the function is called with envp as NULL, then it's assumed that t_ctrl*
 * was already initialized. So instead of initializing the struct, the
 * scan_controllers() function returns that already initialized struct.
 * This makes 'controllers' accessible anywhere in the program.
 *
 * @param	char	*envp[]	- program’s environment variable.
 *
 * @return
 * 	- t_ctrl*	- main variable of the program.
*/
t_ctrl	*scan_controllers(char *envp[])
{
	static t_ctrl	*controllers = NULL;

	if (!envp)
		return (controllers);
	controllers = (t_ctrl *)ft_calloc(1, sizeof(t_ctrl));
	if (!controllers)
		exit_shell();
	controllers->shell = SHELL;
	controllers->prompt = PROMPT;
	controllers->envp = get_controllers_envp(envp);
	controllers->path = get_controllers_path(envp);
	controllers->home = get_controllers_home(envp);
	controllers->error = null;
	controllers->debugger = false;
	return (controllers);
}

char	*scan_pwd(char *new)
{
	t_list	*envp;
	char	*content;

	envp = scan_controllers(NULL)->envp;
	while (envp)
	{
		content = (char *)envp->content;
		if (ft_strncmp(content, "PWD=", 4) == 0)
		{
			if (new)
			{
				envp->content = ft_strdup(new);
				free(new);
			}
			return (content);
		}
		envp = envp->next;
	}
	return (NULL);
}

char	*scan_old_pwd(char *new)
{
	t_list	*envp;
	char	*content;

	envp = scan_controllers(NULL)->envp;
	while (envp)
	{
		content = (char *)envp->content;
		if (ft_strncmp(content, "OLDPWD=", 7) == 0)
		{
			if (new)
			{
				envp->content = ft_strdup(new);
				free(new);
			}
			return (content);
		}
		envp = envp->next;
	}
	return (NULL);
}

/*
 * This function creates a list of strings containing all the enviroment
 * variables from the program's environment - envp.
 *
 * @param	char	*envp[]	- program’s environment variable.
 *
 * @return
 * 	- t_list*	- list of char containing the enviroment variables.
*/
t_list	*get_controllers_envp(char *envp[])
{
	int		i;
	t_list	*list;

	i = 0;
	list = NULL;
	while (envp[i])
		ft_lst_add_back(&list, ft_lst_new(ft_strdup(envp[i++])));
	return (list);
}

/*
 * This function creates a char array containing all the paths to executable
 * files from the $PATH variable of the program's environment - envp.
 *
 * @param	char	*envp[]	- program’s environment variable.
 *
 * @return
 * 	- char**	- array of char containing the all paths to executable files.
*/
char	**get_controllers_path(char *envp[])
{
	int		i;
	char	**path;
	char	*temp;

	i = 0;
	while (envp[i++])
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
	path = ft_split(&envp[i][5], ':');
	i = 0;
	while (path[i])
	{
		temp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		free(temp);
		i++;
	}
	return (path);
}

/*
 * This function creates a char* containing the pathname of the user's home
 * directory from the $HOME variable of the program's environment - envp.
 *
 * @param	char	*envp[]	- program’s environment variable.
 *
 * @return
 * 	- char*	- string of characters containing the pathname of the user's home
 * 			directory.
*/
char	*get_controllers_home(char *envp[])
{
	int		i;

	i = 0;
	while (envp[i++])
		if (ft_strncmp(envp[i], "HOME=", 5) == 0)
			break ;
	return (ft_strdup(&envp[i][5]));
}
