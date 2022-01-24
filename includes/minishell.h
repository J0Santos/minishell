/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:22:55 by josantos          #+#    #+#             */
/*   Updated: 2022/01/24 15:02:09 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* External Functions */
# include <term.h>
# include <signal.h>
# include <curses.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

/* general headers */
# include "libft.h"
# include "color.h"
# include "types.h"
# include "utils.h"

/* mlanca-c's headers */
# include "cli.h"
# include "signals.h"
# include "parser.h"
# include "execution.h"
# include "word_expansion.h"

/* josantos' headers */
# include "builtins.h"

#endif /* MINISHELL_H */
