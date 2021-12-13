/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:22:01 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/12 14:10:44 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

void	signals(void);
void	handler_sigint(int signum, siginfo_t *info, void *context);
void	handler_sigquit(int signum, siginfo_t *info, void *context);

#endif /* SIGNALS_H */