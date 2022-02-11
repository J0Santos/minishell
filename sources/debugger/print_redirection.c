/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:09:01 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/02/11 12:18:46 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_command_red(t_list *red)
{
	static char	*type[] = {"LESS", "GREAT", "DLESS", "DGREAT", NULL};
	t_red		*content;

	if (!red)
	{
		printf("(null)");
		return ;
	}
	printf(" [ Redirection ]:\n");
	while (red)
	{
		content = (t_red *)red->content;
		printf("  [ io_type ]: %s\n", type[content->io_type - 2]);
		printf("  [ io_file ]: %s\n", content->io_file);
		red = red->next;
	}
}
