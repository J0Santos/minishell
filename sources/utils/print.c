/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:09:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/04 20:12:49 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_list *token_list)
{
	static char	*type[] = {"word", "assignment_word", "io_number", 	"pipe",
	"less", "great", "dless", "dgreat", "and_if", "or_if", NULL};
	t_token		*token;

	printf("Tokens:\n");
	while (token_list)
	{
		token = (t_token *)token_list->content;
		printf("\ttext: %s\n", token->text);
		printf("\ttype: %s\n", type[token->type]);
		token_list = token_list->next;
		printf("\n");
	}
}

void	print_controllers(t_ctrl *controllers)
{
	int	i;

	printf("Controllers:\n");
	printf("\tShell: %s\n", controllers->shell);
	printf("\tPrompt: %s\n", controllers->prompt);
	printf("\ttoken_list: %p\n", &controllers->token_list);
	i = 0;
	printf("\tpath:\n");
	while (controllers->path[i])
	{
		printf("\t\t- %s\n", controllers->path[i]);
		i++;
	}
	printf("\tHome: %s\n", controllers->home);
}

void	print_parser(t_parse *parser)
{
	static char	*type[] = {"Simple Command", "Pipeline", "List",
	"Here-Document", NULL};

	printf("Type: %s\n", type[parser->type]);
	print_commands((t_cmd *)parser->command);
}

void	print_commands(t_cmd *command)
{
	static char	*type[] = {"word", "assignment_word", "io_number", 	"pipe",
	"less", "great", "dless", "dgreat", "and_if", "or_if", NULL};
	t_token		*token;

	printf("\tCommand: %s\n", command->cmd_name);
	printf("\targuments: [\n\n");
	while (command->cmd_arguments)
	{
		token = (t_token *)command->cmd_arguments->content;
		printf("\t\ttext: %s\n", token->text);
		printf("\t\ttype: %s\n", type[token->type]);
		command->cmd_arguments = command->cmd_arguments->next;
		printf("\n");
	}
	printf("\t]\n");
}
